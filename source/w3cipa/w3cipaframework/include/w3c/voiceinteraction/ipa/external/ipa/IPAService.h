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

#ifndef IPASERVICE_H
#define IPASERVICE_H

#include <memory>

#include "w3c/voiceinteraction/ipa/external/ProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * @brief The IPAService class
 * The IPAService is the base class for the IPA service.
 * @author Dirk Schnelle-Walka
 */
class IPAService {
public:
    /**
     * Constructs a new object.
     * @param service The provider selection service.
     */
    IPAService();

    /**
     * Destroys the object.
     */
    virtual ~IPAService();

protected:
};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPASERVICE_H
