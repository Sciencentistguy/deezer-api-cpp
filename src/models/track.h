#pragma once
#include <ostream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "album.h"
#include "artist.h"
class Album;

class Track {
    int id;
    bool readable{};
    std::string title;
    std::string title_short;
    std::string title_version;
    bool unseen{};
    std::string isrc;
    std::string link;
    std::string share;
    int duration{};
    int track_position{};
    int disc_number{};
    int rank{};
    // date release_date;
    bool explicit_lyrics{};
    int explicit_content_lyrics{};
    int explicit_content_cover{};
    std::string preview;
    double bpm{};
    double gain{};
    std::vector<std::string> available_countries;
    // Track alternative;
    // Artist artist;
    std::shared_ptr<Album> album;
    std::shared_ptr<Artist> artist;

 public:
    const std::shared_ptr<Artist> getArtist() const;

 public:
    Track(const nlohmann::json& track_json);
    Track() = default;
    int getId() const;
    bool isReadable() const;
    const std::string& getTitle() const;
    const std::string& getTitleShort() const;
    const std::string& getTitleVersion() const;
    bool isUnseen() const;
    const std::string& getIsrc() const;
    const std::string& getLink() const;
    const std::string& getShare() const;
    int getDuration() const;
    int getTrackPosition() const;
    int getDiscNumber() const;
    int getRank() const;
    bool isExplicitLyrics() const;
    int getExplicitContentLyrics() const;
    int getExplicitContentCover() const;
    const std::string& getPreview() const;
    double getBpm() const;
    double getGain() const;
    const std::vector<std::string>& getAvailableCountries() const;
    friend bool operator==(const Track& lhs, const Track& rhs);
    std::shared_ptr<const Album> getAlbum() const;
    friend std::ostream& operator<<(std::ostream& os, const Track& track);
};