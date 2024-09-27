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

#if !defined(IPAPROVIDER_H)
#define IPAPROVIDER_H

#include <string>
#include <list>

#include "w3c/voiceinteraction/ipa/ClientRequest.h"
#include "w3c/voiceinteraction/ipa/ExternalClientResponse.h"
#include "w3c/voiceinteraction/ipa/ModalityType.h"
#include "w3c/voiceinteraction/ipa/Language.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * Interface for IPA providers.
 *
 * An IPA provider is able to access an external IPA and return the response
 * to inside this IPA. It is identified by a unique ID.
 *
 * @author Dirk Schnelle-Walka
 */
class IPAProvider {

public:
    /**
     * Constructs a new object.
     */
    IPAProvider();

    /**
     * Destroys this object.
     */
    virtual ~IPAProvider();

    /**
     * Retrieves a list of languages that are supported by this IPA provider.
     * @return the supported languages of this IPA provider.
     */
    virtual const std::list<Language>& getSupportedLanguages() const = 0;

    /**
     * Retrieves a list modality type that are supported as input by this IPA
     *      provider.
     * @return the supported input modality types of this modality component.
     */
    virtual const std::list<ModalityType> getSupportedModalityTypes() const = 0;

    /**
     * Processes the input from the client.
     * @param request the request coming from the client
     */
    virtual const std::shared_ptr<ExternalClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request) = 0;

    /**
     * Returns the IPA provider's ID.
     * @return the IPA provider's ID.
     */
    virtual const std::string getId() const = 0;

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other IPA provider
     * @return {@code true} in case the
     *          {@code getId() < other.getId()}.
     */
    bool operator<(const IPAProvider& other) const;

    /**
     * @brief operator ==
     * @param other the other IPA provider
     * @return {@code true} in case the
     *          {@code getId() == other.getId()}.
     */
    bool operator==(const IPAProvider& other) const;
};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(IPAPROVIDER_H)
