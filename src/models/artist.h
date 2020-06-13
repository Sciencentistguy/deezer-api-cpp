#pragma once

#include <string>

#include <nlohmann/json.hpp>
class Artist {
    int id;
    std::string name;
    std::string link;
    std::string share;
    std::string picture;
    std::string picture_small;
    std::string picture_medium;
    std::string picture_big;
    std::string picture_xl;
    int nb_album;
    int fans;
    bool radio;
    std::string tracklist;

 public:
    explicit Artist(nlohmann::json artist_json);
    int getId() const;
    const std::string& getName() const;
    const std::string& getLink() const;
    const std::string& getShare() const;
    const std::string& getPicture() const;
    const std::string& getPictureSmall() const;
    const std::string& getPictureMedium() const;
    const std::string& getPictureBig() const;
    const std::string& getPictureXl() const;
    int getNbAlbum() const;
    int getFans() const;
    bool isRadio() const;
    const std::string& getTracklist() const;
};

