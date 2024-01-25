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
			/**
			 * This class represents a set of multi modal outputs.
			 */
            class MultiModalOutputs
			{

			public:
            	/**
            	 * Constructs an empty set of multi modal outputs.
            	 */
                MultiModalOutputs() {
				}

                /**
                 * Destroys the set of multi modal outputs.
                 */
                virtual ~MultiModalOutputs() {
                }

				/**
				 * Adds a multi modal output to the set.
				 * @param output The multi modal output to add.
				 */
                void addMultiModalOutput(const std::shared_ptr<MultiModalOutput> output) {
                    outputs[output->getModality()] = output;
                }

				/**
				 * Returns the multi modal output for the given modality.
				 * @param modality The modality to get the multi modal output for.
				 * @return The multi modal output for the given modality.
				 */
                std::shared_ptr<MultiModalOutput> getMultiModalOutput(const std::string& modality) {
                    return outputs[modality];
                }
            private:
				/**
				 * The map of known multi modal outputs.
				 */
                std::map<std::string, std::shared_ptr<MultiModalOutput>> outputs;
			};

		}

	}

}
#endif // !defined(MULTIMODALOUTPUTS_H)
