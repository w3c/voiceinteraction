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

#ifndef HTTPEXCEPTION_H
#define HTTPEXCEPTION_H

#include<string>
#include <exception>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

/**
 * An error in an HTTP request has been detected.
 * @author Dirk Schnelle-Walka
 */
class HTTPException : public std::exception {
public:
    /**
     * Constructs a new object.
     * @param code error code
     * @param detailed error message
     */
    HTTPException(int code, const std::string& message) 
        : code(code), message(message) {
    }

    /**
     * {@inheritDoc}
     */
    const char* what() const noexcept override {
        return message.c_str();
    }

    /**
     * Retrieves the HTTP status code.
     * @return the code
     */
    const int getCode() const {
        return code; 
    }

 private:
    /** The HTTP status code. */
    int code;
    /** The detail error message. */
    std::string message;
};

}  // namespace chatgpt
}  // namespace ipa
}  // namespace external
}  // namespace reference
}  // namespace ipa
}  // namespace voiceinteraction
}  // namespace w3c

#endif  // HTTPEXCEPTION_H
