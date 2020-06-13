#pragma once
#include <nlohmann/json.hpp>

#include "artist.h"
#include "track.h"
class Track;

class Album {
 private:
    int id;
    std::string title;
    std::string upc;
    std::string link;
    std::string share;
    std::string cover;
    std::string cover_small;
    std::string cover_medium;
    std::string cover_big;
    std::string cover_xl;
    int genre_id;
    // std::vector<Genre> genres;
    std::string label;
    int nb_tracks;
    int duration;
    int fans;
    int rating;
    // Date release_date;
    std::string record_type;
    bool available;
    // Album alternative;
    std::string tracklist;
    bool explicit_lyrics;
    int explicit_content_lyrics;
    int explicit_content_cover;
    std::vector<Artist> contributors;
    std::shared_ptr<Artist> artist;
    std::vector<Track> tracks;

 public:
    explicit Album(nlohmann::json album_json);
    int getId() const;
    const std::string& getTitle() const;
    const std::string& getUpc() const;
    const std::string& getLink() const;
    const std::string& getShare() const;
    const std::string& getCover() const;
    const std::string& getCoverSmall() const;
    const std::string& getCoverMedium() const;
    const std::string& getCoverBig() const;
    const std::string& getCoverXl() const;
    int getGenreId() const;
    const std::string& getLabel() const;
    int getNbTracks() const;
    int getDuration() const;
    int getFans() const;
    int getRating() const;
    const std::string& getRecordType() const;
    bool isAvailable() const;
    const std::string& getTracklist() const;
    bool isExplicitLyrics() const;
    int getExplicitContentLyrics() const;
    int getExplicitContentCover() const;
    const std::vector<Track>& getTracks() const;
    const std::vector<Artist>& getContributors() const;
    const std::shared_ptr<Artist> getArtist() const;
};