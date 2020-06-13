#include "track.h"

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
    //    std::cout << track_json.dump() << '\n';
    auto album_json = track_json.value("album", "{}"_json);
    if (album_json == "{}"_json) {
        album = nullptr;
    } else {
        album = std::make_shared<Album>(album_json);
    }
    auto artist_json = track_json.value("artist", "{}"_json);
    if (artist_json == "{}"_json) {
        artist = nullptr;
    } else {
        artist = std::make_shared<Artist>(artist_json);
    }
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
bool operator==(const Track& lhs, const Track& rhs) {
    return lhs.id == rhs.id;
}

std::shared_ptr<const Album> Track::getAlbum() const {
    return album;
}

std::ostream& operator<<(std::ostream& os, const Track& track) {
    os << "<Track id: " << track.id << " title: " << track.title << '>';
    return os;
}
const std::shared_ptr<Artist> Track::getArtist() const {
    return artist;
}
