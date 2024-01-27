
#if !defined(MODAILTYTYPE_H)
#define MODAILTYTYPE_H

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The SessionId interface is used to identify a session.
 */
class ModalityType {
public:
    /**
     * Contructs a new ModalityType.
     * @param modalityType A human readable string identifying the modality
     *          type.
     */
    ModalityType(const std::string& modalityType)
        : modalityType(modalityType) {
    }

    /**
     * Copy constructor.
     * @param other the other modality to copy from.
     */
    ModalityType(const ModalityType& other)
        : modalityType(other.getModalityType()) {
    }

    /**
     * Destroys the object.
     */
    virtual ~ModalityType() {
    }

    /**
     * Returns the modality type.
     * @return The modality type.
     */
    const std::string& getModalityType() const {
        return modalityType;
    }

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other modality
     * @return {@code true} in case the
     *          {@code getModalityType() < other.getModalityType()}.
     */
    bool operator<(const ModalityType& other) const
    {
        return modalityType < other.getModalityType();
    }

    /**
     * @brief operator =
     * @param other the other modality
     */
    void operator=(const ModalityType& other) {
        modalityType = other.getModalityType();
    }

    /**
     * @brief operator ==
     * @param other the other modality
     * @return {@code true} in case the
     *          {@code getModalityType() == other.getModalityType()}.
     */
    bool operator==(const ModalityType& other) const {
        return modalityType == other.getModalityType();
    }

private:
    /** A human readable string identifying the modality type. */
    std::string modalityType;

};


} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MODAILTYTYPE_H)
