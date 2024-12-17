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

#if !defined(MULTIMODALDATACOLLECTION_H)
#define MULTIMODALDATACOLLECTION_H

#include <memory>
#include <map>
#include <list>

#include "ModalityType.h"
#include "MultiModalData.h"
#include "Language.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class contains a set of multimodal inputs. This implementation
 * allows for only on input per modality.
 * @author Dirk Schnelle-Walka
 */
class MultiModalDataCollection {

public:
    /**
     * Constructs an empty set of multimodal inputs.
     */
    MultiModalDataCollection();

    /**
     * Destroys the set of multimodal inputs.
     */
    virtual ~MultiModalDataCollection();

    /**
     * Adds a multimodal input to the set. An existing entry for the
     * provided modality will be overwritten.
     * @param input The multimodal input to add.
     */
    void addMultiModalData(const std::shared_ptr<MultiModalData>& input);

    /**
     * Returns the multimodal data elements for the given modality.
     * @param modality The modality to return.
     * @return The multimodal data for the given modality, {@code nullptr} if
     *  the modality could not be found.
     */
    std::shared_ptr<MultiModalData> getMultiModalData(const ModalityType& modality) const;

    /**
     * Retrieves all modality types provided in this multimodal data collection.
     * @return list of all modality types
     */
    std::list<ModalityType> getMultiModalData() const;

    /**
     * Retrieves all languages supported by this multimodal data collection.
     * @return list of all supported languages
     */
    std::list<Language> getInputLanguages() const;

    /**
     * Retrieves all modality types provided.
     * @return list of all modality types
     */
    std::list<ModalityType> getModalityTypes() const;

   private:
    /**
     * The map of known multimodal data elements.
     */
    std::map<ModalityType, std::shared_ptr<MultiModalData>> multiModalData;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MULTIMODALDATACOLLECTION_H)
