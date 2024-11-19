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

#ifndef CHATGPTCONFIGURATION_H
#define CHATGPTCONFIGURATION_H

#include <nlohmann/json.hpp>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

struct ChatGPTConfiguration {
  std::string endpoint;
  std::string key;
  std::string systemMessage;
};

void from_json(const nlohmann::json& j, ChatGPTConfiguration& config) {
  j.at("endpoint").get_to(config.endpoint);
  j.at("key").get_to(config.key);
  j.at("systemMessage").get_to(config.systemMessage);
}

} // chatgpt
} // ipa
} // external
} // namespace reference
} // ipa
} // voiceinteraction
} // w3c

#endif // CHATGPTCONFIGURATION_H
