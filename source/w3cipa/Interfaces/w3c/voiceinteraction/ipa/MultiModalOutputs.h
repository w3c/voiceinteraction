///////////////////////////////////////////////////////////
//  MultiModalOutput.h
//  Implementation of the Interface MultiModalOutput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(MULTIMODALOUTPUTS_H)
#define MULTIMODALOUTPUTS_H

#include <memory>
#include <map>

#include "MultiModalOutput.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
            class MultiModalOutputs
			{

			public:
                MultiModalOutputs() {
				}

                virtual ~MultiModalOutputs() {
                }

                void addMultiModalOutput(const std::shared_ptr<MultiModalOutput> output) {
                    outputs[output->getModality()] = output;
                }

                std::shared_ptr<MultiModalOutput> getMultiModalOutput(const std::string& modality) {
                    return outputs[modality];
                }
            private:
                std::map<std::string, std::shared_ptr<MultiModalOutput>> outputs;
			};

		}

	}

}
#endif // !defined(MULTIMODALOUTPUTS_H)
