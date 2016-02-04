# Introduction #

The ESAPI C++ project offers a traditional makefile for building and installing the library. In addition to vanilla make recipe, a number of additional targets are offered to help work with the library and its components.

# Dependencies #

The library has external dependencies, and the topic is covered at [DevPrerequisites](DevPrerequisites.md). While the prerequisites pages includes information on installing developer and debug packages, debug packages are not needed to build and install the ESAPI library. That is, rather than installing libboost, libboost-devel, and libboost-debug, you will only need libboost and libboost-devel (libboost-devel provides necessary header files).

# Build and Targets #

The Makefile includes rules and recipes for both builds and targets. The default makefile rule is `test`.

## Builds ##

For builds, the makefile understands:

  * debug
  * release
  * test

When invoking make with a debug, ie, `make debug`, `CXXFLAGS` will be modified to include the flags `-DDEBUG=1 -g3 -ggdb -O0 -Dprivate=public -Dprotected=public`. Basically, this build offers maximum debug information and access to protected and private class members for testing. In addition, ASSERTS will be in force (by design, ESAPI's ASSERT does not call signal SIGABRT).

`make release` causes CXXFLAGS to include `-DNDEBUG=1 -g -O2`. These are tradition Release build flags. ASSERTS are off.

`make test` is a combination of debug and release: `-DESAPI_NO_ASSERT=1 -g2 -ggdb -O0 -Dprivate=public -Dprotected=public`. The test build turns off ASSERT so the negative self tests do not clutter output.

## Targets ##

For targets, the makefile understands:
  * all
  * static
  * dynamic
  * test
  * install
  * uninstall
  * clean
  * root
  * errors
  * crypto
  * reference
  * util

`make all` will build the static and dynamic libraries using the default `release` (since neither {debug|release|test} was specified).

`make static` will build libesapic++.a, and `make dynamic` will build libesapic++.so. The libraries are placed in the project's lib/ directory. Since neither {debug|release|test} was specified, the libraries will be built with `release` settings.

`make test` serves a dual purpose. First, it sets `CXXFLAGS` as described in **Builds**. Second, it builds and runs the test suite. The test suite executable is 'run\_esapi\_tests' and is located in the project's test/ directory.

`make install` will copy the header files, dynamic library, and static library to customary locations. If you don't specify overrides for `$prefix`, `$exec_prefix`, `$includedir`, or `$libdir`, the locations will be `/usr/local/include` and `/usr/local/lib`. Make copies the libraries which are present, and does not build a missing library. See **Examples** below for examples of different configurations and invocations.

`make uninstall` removes the header files and libraries; while `make clean` will remove temporary, static and dynamic libraries, and run\_esapi\_tests.

`root`, `errors`, `crypto`, `reference`, and `util` are internal components of the ESAPI library. The separate targets are offered to spped development. For example, issuing `make crypto` will build only the sources in the crypto/ subdirectory.

# CXXFLAGS #

ESAPI has chosen its flags and warnings carefully. However, if you would like an addition flag present, specifiy it on the command line:

> `make CXXFLAGS=-DMyCoolDefine`

by default, ESAPI does not include `-fwrapv` (see http://www.airs.com/blog/archives/120). To include the flag:

> `make CXXFLAGS=-fwrapv`

Note that ESAPI will not override you project settings by discarding what you specify. But the project **will** 'tack on' its own flags and switches via 'override'. For example, the following instructs the GNU tools use hidden visibility by default (see http://people.redhat.com/drepper/dsohowto.pdf):

> `ifeq ($(GCC40_OR_LATER),1)`

> `  override CXXFLAGS += -fvisibility=hidden`

> `endif`

If you don't want ESAPI tacking on flags and settings, `s/override//g`.

# Directories #

To pick up any libraries and packages that might be installed in place of a distribution's standard (and sometimes outdated) package, the makefile will use local paths before standard paths. For example,

> `CXXFLAGS += -I. -I./esapi -I./deps -I/usr/local/include -I/usr/include`

> `...`

> `LDFLAGS += -L/usr/local/lib -L/usr/lib`

# Examples #

To build and install a release configuration of the libraries:
> `make all`

> `sudo make install`

To build and install a release configuration of the libraries, using the Comodo compiler:
> `make all CXX=como`

> `sudo make install`

To build and install a release configuration of the libraries, using the intel compiler:
> `make all CXX=icpc`

> `sudo make install`

To build and install a checked configuration of the static library:
> `make debug static`

> `sudo make install`

To build and install a test configuration of the dynamic library:
> `make test dynamic`

> `sudo make install`

To build and install a configuration with both the static and dynamic libraries into `/usr`:
> `make test static`

> `make test dynamic`

> `sudo make install prefix=/usr`

To build and install a release configuration of the libraries, using `/usr/local/foo/bar` as the installation root (ie, install into `/usr/local/foo/bar/include` and `/usr/local/foo/bar/lib`):
> `make release all`

> `sudo make install prefix=/usr/local/foo/bar`

To build and install a release configuration of the libraries, using `/usr/local/foo/bar` as the installation root and `/usr/local/foo/bar/lib64`
> `make release all`

> `sudo make install prefix=/usr/local/foo/bar libdir=/usr/local/foo/bar/lib64`