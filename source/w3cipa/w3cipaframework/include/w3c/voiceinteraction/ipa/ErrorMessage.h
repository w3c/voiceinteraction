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

#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief A basic error message.
 * @author Dirk Schnelle-Walka
 */
class ErrorMessage {
public:
    /**
     * Constructs a new object.
     * @param code the error code
     * @param message the error message
     * @param id the component that caused or handled this error
     */
    ErrorMessage(int code, const std::string& message, const std::string& id);

    /**
     * Destroys this object.
     */
    virtual ~ErrorMessage();

    /**
     * Retrieves the error code.
     * @return the error code.
     */
    int getErrorCode() const;

    /**
     * Retrieves the error message.
     * @return the error message
     */
    const std::string& getErrorMessage() const;

    /**
     * Retrieves the component id.
     * @return the component id
     */
    const std::string& getComponentId() const;

private:
    /** The error code. */
    int errorCode;
    /** The error message. */
    std::string errorMessage;
    /** The component id that caused or handled this error. */
    std::string componentId;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c


#endif // ERRORMESSAGE_H
