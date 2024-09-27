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


#include "w3c/voiceinteraction/ipa/Language.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

const Language Language::DE = Language::Language("de");
const Language Language::EN = Language::Language("en");
const Language Language::ES = Language::Language("es");
const Language Language::FR = Language::Language("fr");
const Language Language::IT = Language::Language("it");
const Language Language::JA = Language::Language("ja");
const Language Language::KO = Language::Language("ko");
const Language Language::NL = Language::Language("nl");
const Language Language::PL = Language::Language("pl");
const Language Language::PT = Language::Language("pt");
const Language Language::RU = Language::Language("ru");
const Language Language::ZH = Language::Language("zh");


Language::Language(const std::string& primary, const std::string& sub)
    : primaryTag(primary), subTag(sub) {
}

Language::~Language() {
}

std::string Language::toString() const {
    std::string out = primaryTag;
    if (!subTag.empty()) {
        out += "-";
        out += subTag;
    }
    return out;
}

bool Language::operator==(const Language& other) const {
    return primaryTag == other.primaryTag && subTag == other.subTag;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
