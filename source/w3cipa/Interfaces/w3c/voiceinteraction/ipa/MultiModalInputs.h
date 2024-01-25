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
			/**
			 * This class contains a set of multimodal inputs.
			 */
            class MultiModalInputs
			{

			public:
            	/**
            	 * Constructs an empty set of multimodal inputs.
            	 */
                MultiModalInputs() {
				}

                /**
                 * Destroys the set of multimodal inputs.
                 */
                virtual ~MultiModalInputs() {
                }

                /**
                 * Adds a multimodal input to the set.
                 * @param input The multimodal input to add.
                 */
                void addMultiModalInput(const std::shared_ptr<MultiModalInput> input) {
                    inputs[input->getModality()] = input;
                }

				/**
				 * Returns the multimodal input for the given modality.
				 * @param modality The modality to return.
				 * @return The multimodal input for the given modality.
				 */
                std::shared_ptr<MultiModalInput> getMultiModalInput(const std::string& modality) {
                    return inputs[modality];
                }
            private:
				/**
				 * The map of known multimodal inputs.
				 */
                std::map<std::string, std::shared_ptr<MultiModalInput>> inputs;
			};

		}

	}

}
#endif // !defined(MULTIMODALINPUTS_H)
