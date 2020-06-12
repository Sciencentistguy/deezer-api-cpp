#include "Track.h"

#include <iostream>

Track::Track(const nlohmann::json& track_json) :
    id{track_json.value("id", 0)}, readable{track_json.value("readable", true)}, title{track_json.value("title", "")},
    title_short{track_json.value("title_short", "")}, title_version{track_json.value("title_version", "")}, unseen{track_json.value("unseen", false)},
    isrc{track_json.value("isrc", "")}, link{track_json.value("link", "")}, share{track_json.value("share", "")}, duration{track_json.value("duration", 0)},
    track_position{track_json.value("track_position", 0)}, disc_number{track_json.value("disk_number", 0)}, rank{track_json.value("rank", 0)},
    /*release_date{track_json.value("release_date", "some sort of null value")},*/
    explicit_lyrics{track_json.value("explicit_lyrics", false)}, explicit_content_lyrics{track_json.value("explicit_content_lyrics", 0)},
    explicit_content_cover{track_json.value("explicit_content_cover", 0)}, preview{track_json.value("preview", "")}, bpm{track_json.value("bpm", 0.0)},
    gain{track_json.value("gain", 0.0)}, available_countries{track_json.value("available_countries", std::vector<std::string>{})} {
}

int Track::getId() const {
    return id;
}

bool Track::isReadable() const {
    return readable;
}

const std::string& Track::getTitle() const {
    return title;
}

const std::string& Track::getTitleShort() const {
    return title_short;
}

const std::string& Track::getTitleVersion() const {
    return title_version;
}

bool Track::isUnseen() const {
    return unseen;
}

const std::string& Track::getIsrc() const {
    return isrc;
}

const std::string& Track::getLink() const {
    return link;
}

const std::string& Track::getShare() const {
    return share;
}

int Track::getDuration() const {
    return duration;
}

int Track::getTrackPosition() const {
    return track_position;
}

int Track::getDiscNumber() const {
    return disc_number;
}

int Track::getRank() const {
    return rank;
}

bool Track::isExplicitLyrics() const {
    return explicit_lyrics;
}

int Track::getExplicitContentLyrics() const {
    return explicit_content_lyrics;
}

int Track::getExplicitContentCover() const {
    return explicit_content_cover;
}

const std::string& Track::getPreview() const {
    return preview;
}

double Track::getBpm() const {
    return bpm;
}

double Track::getGain() const {
    return gain;
}

const std::vector<std::string>& Track::getAvailableCountries() const {
    return available_countries;
}
