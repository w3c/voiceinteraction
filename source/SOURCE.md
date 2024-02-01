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

- Interfaces contains the interfaces as described at https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm
- sources contain the actual reference implementation using these interfaces

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




