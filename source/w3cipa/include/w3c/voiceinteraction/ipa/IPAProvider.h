﻿/*
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

#if !defined(IPAPROVIDER_H)
#define IPAPROVIDER_H

#include <string>

#include "ClientInput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Interface for IPA providers.
 * @author Dirk Schnelle-Walka
 */
class IPAProvider : public ClientInput
{

public:
    /**
     * Constructs a new object.
     */
    IPAProvider() {
    }

    /**
     * Destroys this object.
     */
    virtual ~IPAProvider() {
    }

    /**
     * Returns the IPA provider's ID.
     * @return the IPA provider's ID.
     */
    virtual const std::string getId() const = 0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(IPAPROVIDER_H)
