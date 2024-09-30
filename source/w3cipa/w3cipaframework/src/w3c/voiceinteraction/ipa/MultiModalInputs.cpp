/*
 * IPA Reference Implementation: https://github.com/w3c/voiceinteraction
 *
 * Copyright (C) 2024 World Wide Web Consortium. All Rights Reserved.
 *
 * This work is distributed under the W3C Software and Document License [1]
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] https://www.w3.org/Consortium/Legal/copyright-software
 */

#include "w3c/voiceinteraction/ipa/LanguageDependent.h"
#include "w3c/voiceinteraction/ipa/MultiModalInputs.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

MultiModalInputs::MultiModalInputs() {
}

MultiModalInputs::~MultiModalInputs() {
}

void MultiModalInputs::addMultiModalInput(
    const std::shared_ptr<MultiModalInput>& input) {
    const ModalityType& modality = input->getModality();
    inputs[modality] = input;
}

std::shared_ptr<MultiModalInput> MultiModalInputs::getMultiModalInput(
    const ModalityType& modality) const {
    std::map<ModalityType, std::shared_ptr<MultiModalInput>>::const_iterator iterator =
        inputs.find(modality);
    if (iterator == inputs.end()) {
        return nullptr;
    }
    return iterator->second;
}

/**
 * Retrieves all modality types provided in this input.
 * @return list of all modality types
 */
std::list<ModalityType> MultiModalInputs::getInputModalities() const {
    std::list<ModalityType> types;
    for (std::map<ModalityType,
         std::shared_ptr<MultiModalInput>>::const_iterator iterator = inputs.begin();
         iterator != inputs.end(); ++iterator) {
        types.push_back(iterator->first);
    }
    return types;
}

/**
 * Retrieves all modality types provided in this input.
 * @return list of all modality types
 */
std::list<Language> MultiModalInputs::getInputLanguages() const {
  std::list<Language> languages;
  for (std::map<ModalityType, std::shared_ptr<MultiModalInput>>::const_iterator
       iterator = inputs.begin();
       iterator != inputs.end(); ++iterator) {
    std::shared_ptr<LanguageDependent> languageDependentInput =
        std::dynamic_pointer_cast<LanguageDependent>(iterator->second);
    if (languageDependentInput != nullptr) {
      const Language& language = languageDependentInput->getLanguage();
      languages.push_back(language);
    }
  }
  return languages;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
