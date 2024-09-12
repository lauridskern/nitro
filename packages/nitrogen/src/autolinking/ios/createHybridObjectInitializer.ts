import { NitroConfig } from '../../config/NitroConfig.js'
import { getHybridObjectName } from '../../syntax/getHybridObjectName.js'
import { createFileMetadataString } from '../../syntax/helpers.js'
import type { SourceFile } from '../../syntax/SourceFile.js'
import { indent } from '../../utils.js'

type ObjcFile = Omit<SourceFile, 'language'> & { language: 'objective-c++' }
type SwiftFile = Omit<SourceFile, 'language'> & { language: 'swift' }

export function createHybridObjectIntializer(): [ObjcFile, SwiftFile] {
  const onLoadName = `${NitroConfig.getIosModuleName()}OnLoad`
  const umbrellaHeaderName = `${NitroConfig.getIosModuleName()}-Swift-Cxx-Umbrella.hpp`

  const autolinkedHybridObjects = NitroConfig.getAutolinkedHybridObjects()

  const swiftFunctions: string[] = []
  const cppRegistrations: string[] = []
  const cppIncludes: string[] = []
  let containsSwiftObjects = false
  for (const hybridObjectName of Object.keys(autolinkedHybridObjects)) {
    const config = autolinkedHybridObjects[hybridObjectName]

    if (config?.cpp != null) {
      // Autolink a C++ HybridObject!
      const hybridObjectClassName = config.cpp
      cppIncludes.push(`${hybridObjectClassName}.hpp`)
      cppRegistrations.push(
        `
HybridObjectRegistry::registerHybridObjectConstructor(
  "${hybridObjectName}",
  []() -> std::shared_ptr<HybridObject> {
    static_assert(std::is_default_constructible_v<${hybridObjectClassName}>, "The HybridObject \\"${hybridObjectClassName}\\" is not default-constructible! Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
    return std::make_shared<${hybridObjectClassName}>();
  }
);
      `.trim()
      )
    }
    if (config?.swift != null) {
      // Autolink a Swift HybridObject!
      containsSwiftObjects = true
      const hybridObjectClassName = config.swift
      const swiftNamespace = NitroConfig.getIosModuleName()
      const { HybridTSpecCxx, HybridTSpecSwift } =
        getHybridObjectName(hybridObjectName)
      cppIncludes.push(`${HybridTSpecSwift}.hpp`)
      swiftFunctions.push(
        `
public static func create${hybridObjectName}() -> ${HybridTSpecCxx} {
  let hybridObject = ${hybridObjectClassName}()
  return hybridObject.createCxxBridge()
}
      `.trim()
      )
      cppRegistrations.push(
        `
HybridObjectRegistry::registerHybridObjectConstructor(
  "${hybridObjectName}",
  []() -> std::shared_ptr<HybridObject> {
    auto swiftPart = ${swiftNamespace}::${onLoadName}Swift::create${hybridObjectName}();
    return std::make_shared<${HybridTSpecSwift}>(swiftPart);
  }
);
      `.trim()
      )
    }
  }

  const umbrellaImport = containsSwiftObjects
    ? `#import "${umbrellaHeaderName}"`
    : ''
  const imports = cppIncludes.map((i) => `#import "${i}"`).join('\n')

  const objcCode = `
${createFileMetadataString(`${onLoadName}.mm`)}

#import <Foundation/Foundation.h>
#import <NitroModules/HybridObjectRegistry.hpp>
${umbrellaImport}
#import <type_traits>

${imports}

@interface ${onLoadName} : NSObject
@end

@implementation ${onLoadName}

+ (void) load {
  using namespace margelo::nitro;
  using namespace ${NitroConfig.getCxxNamespace('c++')};

  ${indent(cppRegistrations.join('\n'), '  ')}
}

@end
  `.trim()

  const swiftCode = `
${createFileMetadataString(`${onLoadName}Swift.swift`)}

public final class ${onLoadName}Swift {
  ${indent(swiftFunctions.join('\n\n'), '  ')}
}
  `.trim()

  return [
    {
      content: objcCode,
      language: 'objective-c++',
      name: `${onLoadName}.mm`,
      platform: 'ios',
      subdirectory: [],
    },
    {
      content: swiftCode,
      language: 'swift',
      name: `${onLoadName}Swift.swift`,
      platform: 'ios',
      subdirectory: [],
    },
  ]
}
