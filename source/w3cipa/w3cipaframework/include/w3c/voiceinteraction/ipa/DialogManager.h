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

#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Base class of a dialog manager.
 * @author Dirk Schnelle-Walka
 */
class DialogManager {
public:
    /**
     * Constructs a new object
     */
    DialogManager();

    /**
     * Destroys this instance.
     */
    virtual ~DialogManager();
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // DIALOGMANAGER_H
