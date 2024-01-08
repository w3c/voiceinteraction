///////////////////////////////////////////////////////////
//  MultiModalOutput.h
//  Implementation of the Interface MultiModalOutput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(MULTIMODALINPUTS_H)
#define MULTIMODALINPUTS_H

#include <memory>
#include <map>

#include "MultiModalInput.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
            class MultiModalInputs
			{

			public:
                MultiModalInputs() {
				}

                virtual ~MultiModalInputs() {
                }

                void addMultiModalInput(const std::shared_ptr<MultiModalInput> input) {
                    inputs[input->getModality()] = input;
                }

                std::shared_ptr<MultiModalInput> getMultiModalInput(const std::string& modality) {
                    return inputs[modality];
                }
            private:
                std::map<std::string, std::shared_ptr<MultiModalInput>> inputs;
			};

		}

	}

}
#endif // !defined(MULTIMODALINPUTS_H)
