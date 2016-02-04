# Introduction #

This page discusses compiling for Android and iOS. Before you begin, you should ensure you have the appropriate cross-compiled Crypto++ and Boost libraries available. If you don't have them, you can probably build them following the recipes below (Crypto++ is confirmed, but Boost is a different story).

In general, the Makefile honors all user switches and options (though they may conflict at times). That means you will be able to supply your own set of flags and they will be merged with ESAPI C++'s configuration. Merging ensures, for example, that any include or library paths you add through the command line are present during the execution of a recipe.

# Android #

Compiling Android requires the Android NDK, and the environmental variable `ANDROID_NDK_ROOT` should be set to the root of the NDK. If `ANDROID_NDK_ROOT` is not set, the `setenv-android.sh` script will attempt to locate the NDK in in `$HOME`, `/usr/local`, and `/opt`. For completeness, you should always set `ANDROID_NDK_ROOT` and `ANDROID_SDK_ROOT` because they are used by a number of NDK, SDK, and external tools (see [Recommended NDK Directory?](https://groups.google.com/d/msg/android-ndk/qZjhOaynHXc/2ux2ZZdxy2MJ) for a discussion).

To begin, run `setenv-android.sh`. There are three variables that can be tuned to suit your taste: `_ANDROID_NDK`, `_ANDROID_EABI`, and `_ANDROID_API`. If there are any errors, then you should fix them before proceeding. Note well (_N.B._): be sure to use the leading dot when invoking the command so the changes made by the script are applied to the current shell and child shells.

```
$ . ./setenv-android.sh 
ANDROID_NDK_ROOT: /opt/android-ndk-r8e/
ANDROID_EABI: arm-linux-androideabi-4.6
ANDROID_API: android-14
ANDROID_ARCH: armv7
ANDROID_SYSROOT: /opt/android-ndk-r8e//platforms/android-14/arch-arm
ANDROID_TOOLCHAIN: /opt/android-ndk-r8e//toolchains/arm-linux-androideabi-4.6/prebuilt/darwin-x86_64/bin
ANDROID_STL_INC: /opt/android-ndk-r8e//sources/cxx-stl/stlport/stlport/
ANDROID_STL_LIB: /opt/android-ndk-r8e//sources/cxx-stl/stlport/libs/armeabi/libstlport_static.a
```

A standard Android C++ build does not include the Standard Template Library (STL) by default, so be sure `ANDROID_STL_INC` and `ANDROID_STL_LIB` are valid. They will be added to the appropriate make recipe for the platform.

Once the script sets the environment and variables, you can simply run `make` from the command line. However, you will need to specify `CPP`, `CXX`, and friends because Android uses non-standard names for its tools:

```
$ make test CPP=arm-linux-androideabi-cpp CXX=arm-linux-androideabi-g++ LD=arm-linux-androideabi-ld \
AR=arm-linux-androideabi-ar RANLIB=arm-linux-androideabi-ranlib
```

If all goes well, you will see output similar to below.

![http://owasp-esapi-cplusplus.googlecode.com/svn/trunk/images/esapi-cpp-android.png](http://owasp-esapi-cplusplus.googlecode.com/svn/trunk/images/esapi-cpp-android.png)

To verify the library was built for the device, use `readelf` (alternately, you could check `libesapi-c++.a` or `run_esapi_tests`):

```
$ find . -name libesapi-c++.so
./lib/libesapi-c++.so
$ readelf -h ./lib/libesapi-c++.so | grep -i 'class\|machine'
  Class:                   ELF32
  Machine:                 ARM
```

If building for NEON, then you should supply `CFLAGS` and `CXXFLAGS` recommended by the platform (see [Android ABI Compatibility](https://android.googlesource.com/platform/ndk/+/ics-mr0/docs/STANDALONE-TOOLCHAIN.html) for details):

```
$ make test CFLAGS="-march=armv7-a -mfloat-abi=softfp -mfpu=neon" \
CXXFLAGS="-march=armv7-a -mfloat-abi=softfp -mfpu=neon" \
CPP=arm-linux-androideabi-cpp CXX=arm-linux-androideabi-g++ ...
```

You will likely receive an error due to STLport, and its currently being researched:

```
In file included from src/EncoderConstants.cpp:11:0:
./esapi/EsapiCommon.h:157:12: error: 'std::shared_ptr' has not been declared
./esapi/EsapiCommon.h:158:12: error: 'std::unordered_map' has not been declared
make: *** [src/EncoderConstants.o] Error 1
```

# iOS #

Compiling for iOS requires Xcode and Command Line Tools. The script is built around Xcode 4 and above (location /Applications/Xcode.app) and not Xcode 3 and earlier (location /Developer/Xcode.app). If you want to work with Xcode 3 and earlier, then modify the `XCODE_DEVELOPER` variable. If you want to test on a device, you will also need a developer account for code signing (or a jailbroken device with `ldid`).

To begin, run `setenv-ios.sh`. The script will build for `armv7` by default using the latest SDK it can find. Note well (_N.B._): be sure to use the leading dot when invoking the command so the changes made by the script are applied to the current shell and child shells.

```
$ . ./setenv-ios.sh 
Configuring for Device (ARMv7)
XCODE_SDK: iPhoneOS6.1.sdk
XCODE_DEVELOPER: /Applications/Xcode.app/Contents/Developer
XCODE_TOOLCHAIN: /Applications/Xcode.app/Contents/Developer/usr/bin
XCODE_DEVELOPER_TOP: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer
IOS_ARCH: armv7
IOS_TOOLCHAIN: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/
IOS_SYSROOT: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk
```

Once the script sets the environment and variables, you can simply run `make` from the command line:

```
$ make test
```

If all goes well, you will see output similar to below.

![http://owasp-esapi-cplusplus.googlecode.com/svn/trunk/images/esapi-cpp-ios.png](http://owasp-esapi-cplusplus.googlecode.com/svn/trunk/images/esapi-cpp-ios.png)

To verify the library was built for the device, use `lipo` with the `iphoneos` SDK (alternately, you could check `libesapi-c++.a` or `run_esapi_tests`):

```
$ find . -name libesapi-c++.so
./lib/libesapi-c++.so
$ xcrun -sdk iphoneos lipo -info ./lib/libesapi-c++.so
Non-fat file: ./lib/libesapi-c++.so is architecture: armv7
```

If you want to build for `armv7s`, you can simply execute `setenv-ios.sh` with that argument:

```
$ . ./setenv-ios.sh armv7s
Configuring for Device (ARMv7s)
XCODE_SDK: iPhoneOS6.1.sdk
XCODE_DEVELOPER: /Applications/Xcode.app/Contents/Developer
XCODE_TOOLCHAIN: /Applications/Xcode.app/Contents/Developer/usr/bin
...
```

If you want to build a Mach-O fat binary, the easiest method is to open `GNUmakefile` and add the architectures by hand. Around line 305, make the following change (be sure the appropriate Crypto++ libraries are available):

```
ifeq ($(IS_IOS),1)
  ESAPI_CFLAGS   += -arch armv7 -arch armv7s --sysroot=$(IOS_SYSROOT)
  ESAPI_CXXFLAGS += -arch armv7 -arch armv7s --sysroot=$(IOS_SYSROOT)
endif
```

Finally, if you want to run on a jailbroken device (to avoid the aggravations of `ldid`), then perform a code signing before pushing to the device:

```
codesign -fs "John Doe" test/run_esapi_tests
```