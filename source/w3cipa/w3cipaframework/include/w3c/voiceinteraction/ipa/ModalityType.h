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

#if !defined(MODAILTYTYPE_H)
#define MODAILTYTYPE_H

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief A modality type.
 * 
 * Modality types are used to distinguish the different modalities.
 * @author Dirk Schnelle-Walka
 */
class ModalityType {
public:
    /**
     * Contructs a new ModalityType.
     * @param modalityType A human readable string identifying the modality
     *          type.
     */
    ModalityType(const std::string& modalityType);

    /**
     * Copy constructor.
     * @param other the other modality to copy from.
     */
    ModalityType(const ModalityType& other);

    /**
     * Destroys the object.
     */
    virtual ~ModalityType();

    /**
     * Returns the modality type.
     * @return The modality type.
     */
    const std::string& getModalityType() const;

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other modality
     * @return {@code true} in case the
     *          {@code getModalityType() < other.getModalityType()}.
     */
    bool operator<(const ModalityType& other) const;

    /**
     * @brief operator =
     * @param other the other modality
     */
    void operator=(const ModalityType& other);

    /**
     * @brief operator ==
     * @param other the other modality
     * @return {@code true} in case the
     *          {@code getModalityType() == other.getModalityType()}.
     */
    bool operator==(const ModalityType& other) const;

private:
    /** A human readable string identifying the modality type. */
    std::string modalityType;

};


} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MODAILTYTYPE_H)
