#include "album.h"

#include <iostream>

Album::Album(nlohmann::json album_json) :
    id{album_json.value("id", 0)}, title{album_json.value("title", "")}, upc{album_json.value("upc", "")}, link{album_json.value("link", "")},
    share{album_json.value("share", "")}, genre_id{album_json.value("genre_id", -1)},
    // genres{album_json.value("genres",std::vector<Genre>},
    cover{album_json.value("cover", "")}, cover_small{album_json.value("cover_small", "")}, cover_medium{album_json.value("cover_medium", "")},
    cover_big{album_json.value("cover_big", "")}, cover_xl{album_json.value("cover_xl", "")}, label{album_json.value("label", "")},
    nb_tracks{album_json.value("nb_tracks", 0)}, duration{album_json.value("duration", 0)}, fans{album_json.value("fans", 0)}, rating{album_json.value(
                                                                                                                                   "rating", 0)},
    // release_date{album_json.value("release_date",Date{})},
    record_type{album_json.value("record_type", "")}, available{album_json.value("available", true)},
    // alternative{Album{}},
    tracklist{album_json.value("tracklist", "")}, explicit_lyrics{album_json.value("explicit_lyrics", false)},
    explicit_content_lyrics{album_json.value("explicit_content_lyrics", 0)}, explicit_content_cover{album_json.value("explicit_content_cover", 0)} {
    const auto track_data = album_json.value("tracks", "{}"_json).value("data", "{}"_json);
    if (!(track_data == "{}"_json)) {
        for (auto j : track_data) {
            tracks.push_back(Track(j));
        }
    }

    const auto alternative_json = album_json.value("alternative","{}"_json);
    if (alternative_json == "{}"_json) {
        alternative = nullptr;
    } else {
        alternative = std::make_shared<Album>(alternative_json);
    }

    const auto artist_json = album_json.value("artist", "{}"_json);
    if (artist_json == "{}"_json) {
        artist = nullptr;
    } else {
        artist = std::make_shared<Artist>(artist_json);
    }

    const auto contributors_v = album_json.value("contributors", std::vector<nlohmann::json>{});
    for (const auto& contributor : contributors_v) {
        contributors.push_back(Artist(contributor));
    }

    const auto genres_v = album_json.value("genres", "{}"_json).value("data","{}"_json);
    for (const auto& genre : genres_v) {
        genres.push_back(Genre(genre));
    }
}
int Album::getId() const {
    return id;
}
const std::string& Album::getTitle() const {
    return title;
}
const std::string& Album::getUpc() const {
    return upc;
}
const std::string& Album::getLink() const {
    return link;
}
const std::string& Album::getShare() const {
    return share;
}
const std::string& Album::getCover() const {
    return cover;
}
const std::string& Album::getCoverSmall() const {
    return cover_small;
}
const std::string& Album::getCoverMedium() const {
    return cover_medium;
}
const std::string& Album::getCoverBig() const {
    return cover_big;
}
const std::string& Album::getCoverXl() const {
    return cover_xl;
}
int Album::getGenreId() const {
    return genre_id;
}
const std::string& Album::getLabel() const {
    return label;
}
int Album::getNbTracks() const {
    return nb_tracks;
}
int Album::getDuration() const {
    return duration;
}
int Album::getFans() const {
    return fans;
}
int Album::getRating() const {
    return rating;
}
const std::string& Album::getRecordType() const {
    return record_type;
}
bool Album::isAvailable() const {
    return available;
}
const std::string& Album::getTracklist() const {
    return tracklist;
}
bool Album::isExplicitLyrics() const {
    return explicit_lyrics;
}
int Album::getExplicitContentLyrics() const {
    return explicit_content_lyrics;
}
int Album::getExplicitContentCover() const {
    return explicit_content_cover;
}
const std::vector<Track>& Album::getTracks() const {
    return tracks;
}
const std::vector<Artist>& Album::getContributors() const {
    return contributors;
}
const std::shared_ptr<Artist> Album::getArtist() const {
    return artist;
}
const std::vector<Genre>& Album::getGenres() const {
    return genres;
}
std::shared_ptr<Album> Album::getAlternative() const {
    return alternative;
}
