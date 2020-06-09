# Useful C++ Algorithms

A collection of useful implementations written in C++.

The repository is organized in individual specific projects, and all of them are contained withing the *core* tree (inside `projects/` directory).

Some projects are organized in *full-fledged* structure (e.g. with `include/` and `src/` directories) and other projects (simpler in their core features) are just given as `.cc` sources.

Most of the implementations are done using `C++11` and `C++14` standards.

Local compilation:

* Done on OSX - Catalina
* Using `clang++` provided by XCode
* Build the final repo with `CMake`


**For running the scripts:** On OSX, if XCode is present, the path to the proper SDK should be used as a `CPPFLAG`. Setting the path to the SDK is done with:

```bash
export CXXFLAGS="-isysroot/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/"
```

And then just add the flag into the compilation command

```bash
/path/to/c++/compiler $CXXFLAGS main.cc #optional -std=c++14 if required
```

With extra flag for C++14 standard:

```bash
export CPPFLAGS="-isysroot/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/ -std=c++14"
```


## Asynchronous project

This project is based on some sources and documentation that was already used in another [GitHub Project](https://github.com/basavyr/asyncCPP_Darwin).
* It contains some useful explanations on `moving` the tasks in a container, for example. [here](https://github.com/basavyr/asyncCPP_Darwin/blob/master/sources/AsyncfunctionsC++.md).