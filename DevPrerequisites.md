# Introduction #

The following lists some commands to get Crytpo++ and Boost on the system. It assumes GCC/G++, binutils, make, valgrind, libc6-dev, libc6-dbg, and other friends are already installed. Non-GNU system will also need gmake, If using FreeBSD, issue 'pkg\_add -r gmake', while OpenBSD should enter 'pkg\_add gmake'.

ESAPI uses LeBlanc's SafeInt, Crypto++, and Boost's base installation, regex, and test sub-projects.

A final note on OpenBSD 4.8 and 4.9 (and perhaps others): The default installation ships with GCC 4.2.1, which is broken (see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=21656). You will receive multiple "error: template with C linkage" when using it. Unfortunately, OpenBSD did not take the opportunity to upgrade or patch GCC. Please use a different version of GCC.

## SafeInt ##

SafeInt3.hpp is included in the ESAPI project directory and located in <ESAPI directory>/deps. No action is needed.

## Crypto++ ##

```
# Debian and friends (Ubuntu 11.04 and below)
$ sudo apt-get install libcrypto++8 libcrypto++8-dbg libcrypto++-dev
```

```
# Debian and friends (Ubuntu 11.10 and above)
$ sudo apt-get install libcrypto++9 libcrypto++9-dbg libcrypto++-dev
```

```
# Fedora and friends
> su -
# yum install cryptopp cryptopp-devel
```

## Dmalloc ##

```
# Debian and friends
$ sudo apt-get install libdmalloc5
```

```
# Fedora and friends
$ sudo yum install dmalloc
```

## Boost ##

```
# Debian and friends
$ sudo apt-get install libboost-dev libboost-regex-dev libboost-system-dev libboost-test-dev
```

```
#Fedora and friends
$ sudo yum install boost-devel
```

```
# FreeBSD
> su -
$
$ pkg_add -r boost-libs
```

```
# OpenBSD
> su -
$ pkg_add boost
```

```
# Checking out a release from Boost SVN (useful for `bcp`, which
# allows one to copy out a particular file with dependencies)
$ svn co http://svn.boost.org/svn/boost/tags/release/Boost_1_54_0/ boost-1.54.0
```

## Grepping Package ##

Searching packages can be performed as follows (using boost as an example).

```
# Debian and friends
$ apt-cache pkgnames | grep -i boost | grep -i dev
```

```
# Fedora and friends
> yum search boost | grep -i devel
```

## Win32 ##
A version of ESAPI for Windows x86/x64 is available via a Visual Studio 2008 solution file. The Win32 version of ESAPI will build a static version of the library. The Win32 version does not build the self tests due to problems linking against Boost.

The Win32 version of ESAPI is dependent upon Crypto++ and Boost. The Visual Studio project expects two environmental variables to be set: one for Crypto++ and one for Boost. The Crypto++ variable is named 'CRYPTOPP' and should point to the directory containing Crypto++. For example, if Crypto++ is in a folder on the desktop, the envrioment should be 'CRYPTOPP=C:\...\Desktop'. Additionally, the Crypto++ directory must be named **cryptopp** since its used in an include: `#include "cryptopp/rsa.h"`.

Boost uses the environmental variable 'BOOST', and should include the Boost folder (unlike Crypto++). For example, if Boost is located in 'C:\Program Files\boost\boost\_1\_47', the envrioment should be 'BOOST=C:\Program Files\boost\boost\_1\_47'. Note well (N.B.): remember to build the Crypto++ and Boost libraries to avoid linker errors.

If you do not have a Crypto++ or Boost environmental variable, see http://technet.microsoft.com/en-us/library/bb726962.aspx and http://support.microsoft.com/kb/310519.

The project should convert to VS2010 without trouble. In addition, the project should down-convert to VS2005 by modifying the solution and project file's headers (its just XML, change the version number). Below Visual Studio 2008 uses Version=9.00. To convert to Visual Studio 2005, change the version to 8.00.

```
<?xml version="1.0" encoding="Windows-1252"?>
<VisualStudioProject
    ProjectType="Visual C++"
    Version="9.00"
    ...
```