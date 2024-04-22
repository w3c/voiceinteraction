# Reference Implementation of an IPA Framework

This project aims at providing a reference implementation for an IPA framework.

## Prerequisites

You will need
- A C/C++ compiler supporting at least C++ 17
- CMake version 3.22
- a local copy of libcurl https://curl.se/download.html so that it can be found
  by FindPackage on Windows systems
- A C++ IDE of your choice
- An OpenAI developer key

## Building

### Clone the repository

```
git clone git@github.com:w3c/voiceinteraction.git
```

### Project Structure

The source code is in the folder source/w3cipa

- `w3cipaframework` contains the interfaces as described at
  [Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm).
- `w3cipareferenceimplementation` contains the actual reference implementation of some common components using these interfaces
- `w3cipachatgptipaprovider` an IPAProvider implementation for ChatGPT
- `w3cipademo` contains demo using the reference implementation


### Manual Build

On Windows systems

```
cd source/w3cipa
mkdir build
cd build
cmake .. -DCURL_INCLUDE_DIR=<Your path to the CURL include directory> -DCURL_LIBRARY=<Your path to the CURL library directory>
make && make install
```

On Linux based systems or any other

```
cd source/w3cipa
mkdir build
cd build
cmake ..
make && make install
```

## Demo Code Walkthrough

The current demo aims at interacting with ChatGPT. As a first step you will need
to provide the correct developer key to communicate with ChatGPT.

### Configuring Keys

As of now, everything is hard coded, you will need to replace your OpenAI
developer key in the file w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/chatgptadapter.cpp

Replace `OPENAI-DEVELOPER-KEY` with your actual key

<mark>Take care not to commit while this key is in the source code</mark>

### Main Program

The main program starts with creating all the needed components per layer as
described in 
[Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm).

All components are created as shared instances, as they can potentially be
re-used in the employed processing chain.

#### Client Layer

On the client side, we mainly need the correct modality components, text via
`console` for now, a modality manager `modalityManager` to handle all known 
modalities, and a component to select which input to forward to the 
IPA. In this case, we simply select the first one that reaches us via `inputListener`.

```
std::shared_ptr<client::ModalityManager> modalityManager =
    std::make_shared<client::ModalityManager>();
std::shared_ptr<::reference::client::ConsoleTextModalityComponent> console =
    std::make_shared<::reference::client::ConsoleTextModalityComponent>();
modalityManager->addModalityComponent(console);
std::shared_ptr<::reference::client::TakeFirstInputModalityComponentListener> inputListener =
    std::make_shared<::reference::client::TakeFirstInputModalityComponentListener>();
```

#### Dialog Layer

So far, we do not have an implementation of a dialog manager. However, the IPA
service `ipaService` is used to consume incoming calls from the clients
and provide the corresponding replies. For now, it will also convert
an error, e.g. ChatGPT cannot be reached to a user reply. Later, this will
be taken care of by the dialog mangager.

```
std::shared_ptr<::reference::dialog::ReferenceIPAService> ipaService =
    std::make_shared<::reference::dialog::ReferenceIPAService>();
```

#### External IPA / Services Layer

Here, we create an instance of an `IPAProvider` to communicate with ChatGPT. 
This instance `chatGPT` is added to the list of known IPA providers in the
`registry`. The `providerSelectionStrategy` is used by the `ProviderRegistry`
to selects thos IPA providers that are suited to handle the current request.
In this case, we select all those that have a matching modality, i.e. text.

```
std::shared_ptr<::reference::external::providerselectionservice::ModalityMatchingProviderSelectionStrategy> providerSelectionStrategy =
    std::make_shared<::reference::external::providerselectionservice::ModalityMatchingProviderSelectionStrategy>();
std::shared_ptr<ProviderRegistry> registry =
    std::make_shared<ProviderRegistry>(providerSelectionStrategy);
std::shared_ptr<IPAProvider> chatGPT =
    std::make_shared<::reference::external::ipa::chatgpt::ChatGPTAdapter>();
registry->addIPAProvider(chatGPT);
std::shared_ptr<ProviderSelectionService> providerSelectionService =
    std::make_shared<ProviderSelectionService>(registry);
```

#### Create a Processing Chain

Following 
[Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm)
we then tie those needed components together.

```
modalityManager >> inputListener >> ipaService >> providerSelectionService
        >> ipaService >> modalityManager;
```

#### Start 

Finally, we need to start capturing input and start processing in the IPA

```
modalityManager->startInput();
inputListener->processIPAData(nullptr);
```

#### Demo Output

When running the program `w3cipademo` we may see the following on the screen

```
User: What is the voice interaction community group?
System: The Voice Interaction Community Group (VoiceIG) is a group under the 
World Wide Web Consortium (W3C) that focuses on promoting and enabling the use
of voice technology on the web. This community group aims to facilitate
discussions, share best practices, and collaborate on standards and guidelines
related to voice interactions on the web. The group is open to anyone interested
in voice technology, including developers, designers, researchers, and other
stakeholders in the industry.
```

## License

This code is distributed under the
[Software and Document license - 2023 version](https://www.w3.org/copyright/software-license-2023/).

While the W3C IPA Framework in the folder `include` is a dependency free
implementation without any dependency, the reference implementation in folder 
`source` makes use of 3rd-party software.

- libCURL
    - <https://curl.se/libcurl/>
    - MIT/X like license
- log4cplus
    - <https://github.com/log4cplus/log4cplus>
    - Two clause BSD license
- nlohmann JSON
    - <https://github.com/nlohmann/json>
    - MIT license
- OpenSSL 
    - <https://www.openssl.org/>
    - Apache License 2 
- stduuid 
    - <https://github.com/mariusbancila/stduuid/>
    - MIT License

## Open Issues

A list of open issues can be displayed via
[Open Issues for Reference Implementation](https://github.com/w3c/voiceinteraction/issues?q=is%3Aissue+is%3Aopen+label%3A%22reference+implementation%22).
