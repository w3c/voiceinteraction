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

#if !defined(META_DATA_H)
#define META_DATA_H

#include "Timestamp.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Interfacce for meta data of {@llink w3c::voiceinteraction::ClientRequest}.
 * @author Dirk Schnelle-Walka
 */
class MetaData
{

public:
    /**
     * Constucts a new object.
     */
    MetaData() {
    }

    /**
     * Destroys the object.
     */
    virtual ~MetaData() {
    }

    /**
     * Returns the timestamp of the request.
     */
    virtual const Timestamp& getTimestamp() =0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(META_DATA_H)
