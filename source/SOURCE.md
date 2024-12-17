# Reference Implementation of an IPA Framework

This project aims at providing a reference implementation for an IPA framework.

## Prerequisites

You will need
- A C/C++ compiler supporting at least C++ 22
- CMake version 3.22
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
  [Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm)
  and [Architecture and Potential for Standardization Version](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paArchitecture/paArchitecture-1-3.htm).
- `w3cipareferenceimplementation` contains the actual reference implementation of some common components using these interfaces
- `w3cipachatgptipaprovider` an IPAProvider implementation for ChatGPT
- `w3cipademo` contains demo using the reference implementation

### Configuration Options

The following options can be set in the CMake configuration

| Option | Description | Default |
|--------|-------------|---------|
| BUILD_W3CIPA_DOC | Build documentation | OFF |
| BUILD_W3CIPA_DEPENDENCIES | Build depending libraries from source | ON |

### Manual Build

#### IDE

Most C++-IDEs support CMake as a build system. In the IDE of your choice open
file `w3cipa/CMakeLists.txt`.

#### Console

On Windows systems you will also need to install [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/overview) installed.
Unfortuanately, it is quite a hazzle to get the dependency on CURL compiled in the Windows environment 
and this seems to be the easiest way to get it done.

```
cd source/w3cipa
mkdir build
cd build
cmake ..
make && make install
```

## Demo Code Walkthrough

The current demo aims at interacting with ChatGPT. This Walkthrough will also
give hints about the used components from
[Architecture and Potential for Standardization Version](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paArchitecture/paArchitecture-1-3.htm)

![IPA Architecture](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paArchitecture/IPA-Architecture-1-3.svg)

As a first step you will need to provide the correct developer key to
communicate with ChatGPT.

### Configuring Keys

In order to get started, you will need to replace your OpenAI
developer key in the file 
[voiceinteraction/source/w3cipa/w3cipachatgptipaprovider/ChatGPTIPAProvider.json](https://github.com/w3c/voiceinteraction/blob/5bb7fd5311f8c0da24dd9a40a4fd94145c178cb1/source/w3cipa/w3cipachatgptipaprovider/ChatGPTIPAProvider.json#L3)

Replace `OPENAI-DEVELOPER-KEY` with your actual key.

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
IPA. In this case, we simply select the first one that reaches us via
`inputListener`.

The `modalityManager` and `inputListener` are part of the `IPA Client`. 
`ModalityComponent`s are either the `Capture` or `Presentation` components or
both as in the case of the `console`.

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

Here, we create the `Dialog Manager` and the `ipaService` as an implementation of the `IPA Service`.
The dialog manager mainly separates good calls from erroneous ones and forwards
the reply accordingly.

```
std::shared_ptr<::reference::dialog::ReferenceIPAService> ipaService =
    std::make_shared<::reference::dialog::ReferenceIPAService>();
std::shared_ptr<::reference::dialog::ReferenceIPADialogManager> ipaDialogManager =
    std::make_shared<::reference::dialog::ReferenceIPADialogManager>();
```

#### External IPA / Services Layer

Here, we create an instance of an `IPAProvider` to communicate with ChatGPT. 
This instance `chatGPT` is added to the list of known IPA providers in the
`registry` as an implementation of a `Provider Registry`. 
The `providerSelectionStrategy` is used by the `registry`
to select those IPA providers that are suited to handle the current request.
In this case, we select all those that have a matching modality, i.e. text and
the correct language. A chained filter is used to select the best provider.

The `providerSelectionService` as an implementation of the 
`Provider Selection Service` acts as the main component to be approached
from components in the `Dialog Layer`. It makes use of the `registry` to 
obtain a list of `IPA Providers` that are suited to handle an actual 
request, forwards this request to them and waits until all responses
have been received.

```
// Create a chained filter for selecting the best provider
std::shared_ptr<::external::ipa::ProviderSelectionStrategyList>
    providerSelectionStrategy =
        std::make_shared<::external::ipa::ProviderSelectionStrategyList>();
std::shared_ptr<::external::ipa::LanguageMatchingProviderSelectionStrategy>
    languageProviderSelectionStrategy = std::make_shared<
        ::external::ipa::LanguageMatchingProviderSelectionStrategy>();
providerSelectionStrategy->addStrategy(languageProviderSelectionStrategy);
std::shared_ptr<::external::ipa::ModalityMatchingProviderSelectionStrategy>
    modalityProviderSelectionStrategy =
    std::make_shared<::external::ipa::ModalityMatchingProviderSelectionStrategy>();
providerSelectionStrategy->addStrategy(modalityProviderSelectionStrategy);
// create main components in the external layer
std::shared_ptr<ProviderRegistry> registry =
    std::make_shared<ProviderRegistry>(providerSelectionStrategy);
std::shared_ptr<IPAProvider> chatGPT =
    std::make_shared<::reference::external::ipa::chatgpt::ChatGPTIPAProvider>();
registry->addIPAProvider(chatGPT);
std::shared_ptr<external::ProviderSelectionService> providerSelectionService =
    std::make_shared<external::ProviderSelectionService>(registry);
```

#### Create a Processing Chain

Following 
[Intelligent Personal Assistant Interfaces](https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/paInterfaces.htm)
we then tie those needed components together.

```
modalityManager >> inputListener >> ipaService >> providerSelectionService
        >> ipaDialogManager >> ipaService >> modalityManager;
```

The following shows which components from the diagram above are available
and how this chain maps to it.

![Chained IPA Architecture](docs/IPA-Architecture-ChatGPT.svg)

#### Start 

Finally, we need to start capturing input and start processing in the IPA

```
modalityManager->startInput();
inputListener->IPADataProcessor::processIPAData();
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
