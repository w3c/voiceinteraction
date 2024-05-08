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

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * The IPAService is the base class for the IPA service.
 *
 * Usually, this insance is only needed in case multiple clients need to be
 * handled or the input is forwarded simultaneously to a local IPA and
 * external IPAs.
 *
 * @author Dirk Schnelle-Walka
 */
class IPAService {
public:
    /**
     * Constructs a new object.
     */
    IPAService();

    /**
     * Destroys the object.
     */
    virtual ~IPAService();

};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPASERVICE_H
