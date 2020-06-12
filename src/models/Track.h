#pragma once
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

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
    // Album album;
 public:
    explicit Track(const nlohmann::json& track_json);
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
};