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
#include <memory>
#include "IPAData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief An IPA data processor that consumes, processes, and forwards IPAData.
 * 
 * An IPA data processor is able to consume {@link IPAData}, process it,
 * and forward the processed result to registered other IPA data processors
 * to eventually further process the data.
 * 
 * An example for such a processing chain is shown in the following diagram:<br>
 * <img src="https://w3c.github.io/voiceinteraction/voice%20interaction%20drafts/paInterfaces/IPAData-Processing-Chain.svg" alt="IPA Data Processor Chain">
 * 
 * @note Implementors should ensure that they only handle data they can process.
 *       Due to chaining, inputs may be received from multiple sources.
 *       This method should return immediately if there is nothing to do with the received data.
 * 
 * @see IPAData
 * 
 * @author Dirk Schnelle-Walka
 */
class IPADataProcessor {
public:
    /**
     * @brief Constructs a new IPADataProcessor instance.
     */
    IPADataProcessor();

    /**
     * @brief Destroys the IPADataProcessor instance.
     */
    virtual ~IPADataProcessor();

    /**
     * @brief Starts processing with a null data pointer.
     * 
     * This method calls {@link processIPAData(std::shared_ptr<IPAData> data)} with a null pointer.
     */
    virtual void processIPAData();

    /**
     * @brief Processes the given data and notifies all registered listeners.
     * 
     * Conceptually, this method can be called multiple times depending on
     * how many other processors this instance has been subscribed to.
     * @param data The data to process.
     */
    virtual void processIPAData(std::shared_ptr<IPAData> data) = 0;

    /**
     * @brief Adds the given listener to the list of known listeners.
     * 
     * @param listener The listener to add.
     */
    void addIPADataProcessorListener(const std::shared_ptr<IPADataProcessor>& listener);

    /**
     * @brief Adds the given listener to the list of known listeners.
     * 
     * This is a shortcut for {@link addIPADataProcessorListener(const std::shared_ptr<IPADataProcessor>& listener)}.
     * 
     * @param other The listener to add.
     */
    void operator>>(const std::shared_ptr<IPADataProcessor>& other);

protected:
    /**
     * @brief Asynchronously notifies all listeners about the processed data.
     * 
     * @param data The processed data.
     */
    void notifyListeners(const std::shared_ptr<IPAData>& data);

private:
    /** List of known listeners for processed results. */
    std::list<std::shared_ptr<IPADataProcessor>> listeners;
};

/**
 * @brief Adds the destination processor as a listener to the source processor.
 * 
 * @param source The source processor.
 * @param destination The destination processor.
 * @return The destination processor.
 */
const std::shared_ptr<IPADataProcessor>& operator>>(
        const std::shared_ptr<IPADataProcessor>& source,
        const std::shared_ptr<IPADataProcessor>& destination);

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPADATAPROCESSOR_H
