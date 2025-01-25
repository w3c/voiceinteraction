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
namespace dialog {

/**
 * @class IPAService
 * @brief The IPAService is the base class for the IPA service.
 *
 * The IPAService class is responsible for managing multiple clients and 
 * forwarding input simultaneously to both local and external IPAs.
 * This class is typically instantiated when there is a need to handle 
 * multiple clients or to forward input to various IPAs.
 *
 * @note This class is part of the W3C Voice Interaction framework.
 * @author Dirk Schnelle-Walka
 */
class IPAService {
public:
    /**
     * @brief Constructs a new IPAService object.
     */
    IPAService();

    /**
     * @brief Destroys the IPAService object.
     */
    virtual ~IPAService();

};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPASERVICE_H
