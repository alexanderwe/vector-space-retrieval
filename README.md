# EfficientVectorSpaceRetrieval

An efficient Vector Space Model (VSM) implementation for retrieving medical data, built within the team project of the course Information Retrieval & Web Search.

# Project Structure

## ./

* main.cc - Main entry point, starts application
* CMakeLists.txt - Links `evsr_lib` to main executable `evsr_run`, build documentation, builds tests

## ./src

* CMakeLists.txt builds the `evsr_lib` executable which is linked to the `evsr_run` and the unit tests later on
* Files and directories for our efficient vector space retrieval IR

## ./preprocessing

* preprocess.py - aggregate queries and document collection from [nfcorpus](http://www.cl.uni-heidelberg.de/statnlpgroup/nfcorpus/)

## ./tests

* CMakeLists.txt downloads googletest library if not already installed and builds googletest and our own unit tests

### ./tests/unit_tests

* CMakeLists.txt builds `Unit_Tests_run` and links it against our own `evsr_lib`, `gtest` and `gtest_main`
* Also contains tests for different parts of our library
* Tests can be run by either exectuing `Unit_Tests_run` or Ctest from CMake

# Set Up

To initial everything after cloning or unzipping the repo run `./configure.sh` to create needed directories, download external libraries via CMake and let CMake compile everything.

**IMPORTANT:**

You need to have Boost installed on your machine in order to build the binary. It is recommended to use the `-b` option of `./configure.sh` to tell the script the location of Boost

```
 SYNOPSIS
    configure.sh [-h] [-c[compiler_path]]  [-cxx[compiler_path]]

 DESCRIPTION
    Setting up CMake, directory structure and compile everything to start the main evsr executable

 OPTIONS
    -c [path], --c [path]         Set a custom C compiler path
    -cxx [path], --cxx [path]     Set a custom C++ compiler path

 EXAMPLES
    configure.sh -c "/usr/local/Cellar/gcc/7.3.0_1/bin/gcc-7 -cxx /usr/local/Cellar/gcc/7.3.0_1/bin/g++-7
```

# Server

To use a UI to interact with the binary, you need to have `Node.js` and `npm` installed on your machine.
Issue the following commands :

Build the React application:

```
$ cd ./evsr-server/client
$ npm run build
```

Start the server and visit [localhost:8080](localhost:8080)

```
$ cd ./evsr-server/server
$ npm run start
```

The server uses the build version of the React application. If you want to not use the build React application, issue the following commands in two separate terminal sessions.

1st Terminal

```
$ cd ./evsr-server/client
$ npm run start
```

2nd Terminal

```
$ cd ./evsr-server/server
$ npm run start
```

Then visit [localhost:3000](localhost:3000). This is now the development server of the React applications which interacts with the backend of the server on localhost:8080
