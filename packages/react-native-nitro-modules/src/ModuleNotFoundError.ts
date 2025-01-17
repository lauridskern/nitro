import { NativeModules, Platform } from 'react-native'

declare global {
  // A react-native internal from TurboModuleRegistry.js
  var __turboModuleProxy: unknown | undefined
}

const BULLET_POINT = '\n* '

function messageWithSuggestions(
  message: string,
  suggestions: string[]
): string {
  return message + BULLET_POINT + suggestions.join(BULLET_POINT)
}

function getFrameworkType(): 'react-native' | 'expo' | 'expo-go' {
  // check if Expo
  const ExpoConstants =
    NativeModules.NativeUnimoduleProxy?.modulesConstants?.ExponentConstants
  if (ExpoConstants != null) {
    if (ExpoConstants.appOwnership === 'expo') {
      // We're running Expo Go
      return 'expo-go'
    } else {
      // We're running Expo bare / standalone
      return 'expo'
    }
  }
  return 'react-native'
}

export class ModuleNotFoundError extends Error {
  constructor(cause?: unknown) {
    // TurboModule not found, something went wrong!
    if (global.__turboModuleProxy == null) {
      // TurboModules are not available/new arch is not enabled.
      const message =
        'Failed to get NitroModules: NitroModules require the new architecture to be enabled!'
      const suggestions: string[] = []
      suggestions.push(
        'Enable the new architecture in your app to use NitroModules. (See https://github.com/reactwg/react-native-new-architecture/blob/main/docs/enable-apps.md)'
      )
      const error = messageWithSuggestions(message, suggestions)
      super(error, { cause: cause })
      return
    }

    const framework = getFrameworkType()
    if (framework === 'expo-go') {
      super(
        'NitroModules are not supported in Expo Go! Use EAS (`expo prebuild`) or eject to a bare workflow instead.'
      )
      return
    }

    const message =
      'Failed to get NitroModules: The native "NitroModules" TurboModule could not be found.'
    const suggestions: string[] = []
    suggestions.push(
      'Make sure react-native-nitro-modules/NitroModules is correctly autolinked (run `npx react-native config` to verify)'
    )
    suggestions.push(
      'Make sure you enabled the new architecture (TurboModules) and CodeGen properly generated the "NativeNitroModules"/NitroModulesCxx specs. See https://github.com/reactwg/react-native-new-architecture/blob/main/docs/enable-apps.md'
    )
    suggestions.push(
      'Make sure you are using react-native 0.74.0 or higher, because NitroModules are built with C++ TurboModules.'
    )
    suggestions.push('Make sure you rebuilt the app.')
    if (framework === 'expo') {
      suggestions.push('Make sure you ran `expo prebuild`.')
    }
    switch (Platform.OS) {
      case 'ios':
      case 'macos':
        suggestions.push(
          'Make sure you ran `pod install` in the ios/ directory.'
        )
        break
      case 'android':
        suggestions.push('Make sure gradle is synced.')
        break
      default:
        throw new Error(`NitroModules are not yet supported on ${Platform.OS}!`)
    }

    const error = messageWithSuggestions(message, suggestions)
    super(error, { cause: cause })
  }
}
