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

#ifndef IPADATAPROCESSOR_H
#define IPADATAPROCESSOR_H

#include <list>

#include "IPAData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * An IPA data processor is able to consume {@link IPAData}, process it
 * and forward the processed result to registered other IPA data processors
 * to eventually further process the data.
 * @author Dirk Schnelle-Walka
 */
class IPADataProcessor {
public:
    /**
     * Creates a new instance.
     */
    IPADataProcessor();

    /**
     * Destroys this instance.
     */
    virtual ~IPADataProcessor();

    /**
     * Processes the data and informs all registered listeners afterwards
     * via {@link #notifyListeners}.
     *
     * Conceptually, this method can be called multiple times depending on
     * how many other processors this instance has been subsribed to.
     *
     * Implementors should take care that they only handle those data that
     * they can handle. As a result of chaining, inputs may be received from
     * multiple sources. This method should return immediately, if there is
     * nothing to do with the received data.
     * @param data the data to process;
     */
    virtual void processIPAData(std::shared_ptr<IPAData> data) = 0;

    /**
     * Adds the given listener to the list of known listeners.
     * @param listener the listener to add
     */
    void addIPADataProcessorListener(
            const std::shared_ptr<IPADataProcessor>& listener);

    /**
     * Shortcut for {@link addIPADataProcessorListener(const std::shared_ptr<IPADataProcessor>& listener)}.
     * @param other the listener to add
     */
    void operator >>(const std::shared_ptr<IPADataProcessor>& other);
protected:
    /**
     * Asynchronously notifies all listeners about the processed data.
     * @param data the processed data
     */
    void notifyListeners(const std::shared_ptr<IPAData>& data);

private:
    /** List of known listeners for processed results. */
    std::list<std::shared_ptr<IPADataProcessor>> listeners;
};

const std::shared_ptr<IPADataProcessor>& operator>>(
        const std::shared_ptr<IPADataProcessor>& source,
        const std::shared_ptr<IPADataProcessor>& destination);

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPADATAPROCESSOR_H
