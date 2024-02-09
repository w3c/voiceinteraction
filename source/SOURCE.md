# Reference Implementation of an IPA Framework

This project aims at providing a reference implementation for an IPA framework.

## Prerequisites

You will need
- A C/C++ compiler supporting at least C++ 17
- CMake version 3.24
- a local copy of libcurl https://curl.se/download.html so that it can be found by FindPackage
- A C++ IDE of your choice
- An OpenAI developer key

## Building

### Clone the repository

```
git clone git@github.com:w3c/voiceinteraction.git
```

### Project Structure

The source code is in the folder source/w3cipa

- `include` contains the interfaces as described at [Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm).
- `sources` contain the actual reference implementation using these interfaces

### License

This code is distributed under the [Software and Document license - 2023 version](https://www.w3.org/copyright/software-license-2023/).

While the W3C IPA Framework in the folder `include` is a header-only
implementation without any dependency, the reference implementation in folder 
`source` makes use of 3rd-party software.

- OpenSSL 
    - <https://www.openssl.org/>
    - Apache License 2 
- libCURL
    - <https://curl.se/libcurl/>
    - MIT/X like license
- log4cplus
    - <https://github.com/log4cplus/log4cplus>
    - Two clause BSD license
- nlohmann JSON
    - <https://github.com/nlohmann/json>
    - MIT license

### Configuring Keys

As of now, everything is hard coded, yo you will need to replace your OpenAI developer key in the file w3c/voiceinteraction/ipa/external/ipa/chatgpt/chatgptadapter.cpp

Replace OPENAI-DEVELOPER-KEY with your actual key

<mark>Take care not to commit while this key is in the source code</mark>

### Manual Build

```
cd source/w3cipa
mkdir build
cd build
cmake ..
make && make install
```
## Open Issues

A list of open issues can be displayed via [Open Issues for Reference Implementation](https://github.com/w3c/voiceinteraction/issues?q=is%3Aissue+is%3Aopen+label%3A%22reference+implementation%22).
