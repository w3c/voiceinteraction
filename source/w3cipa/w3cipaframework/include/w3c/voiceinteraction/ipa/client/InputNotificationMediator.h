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

#ifndef INPUTNOTIFICATIONMEDIATOR_H
#define INPUTNOTIFICATIONMEDIATOR_H

#include <list>
#include <memory>

#include "InputModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

class InputNotificationMediator
{
public:
    /**
     * Constructs a new object.
     */
    InputNotificationMediator();

    /**
     * Destroys this object.
     */
    ~InputNotificationMediator();

    /**
     * Adds the provided listener for multimodal inputs to the list of known
     * listeners.
     * @param listener the listener to add.
     */
    void addInputModalityComponentListener(
            const std::shared_ptr<InputModalityComponentListener>& listener);

    /**
     * Notifies all listeners about the received multiomodal input.
     * @param input the input
     */
    void notifyListeners(std::shared_ptr<MultiModalInput> input);

private:
    /** Known listeners for multimnodal input. */
    std::list<std::shared_ptr<InputModalityComponentListener>> inputListeners;

};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // INPUTNOTIFICATIONMEDIATOR_H
