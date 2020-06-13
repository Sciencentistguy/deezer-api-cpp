#pragma once

#include <string>

#include <nlohmann/json.hpp>
class Genre {
    int id;
    std::string name;
    std::string picture;
    std::string picture_small;
    std::string picture_medium;
    std::string picture_big;
    std::string picture_xl;

 public:
    explicit Genre(nlohmann::json genre_json);
    int getId() const;
    const std::string& getName() const;
    const std::string& getPicture() const;
    const std::string& getPictureSmall() const;
    const std::string& getPictureMedium() const;
    const std::string& getPictureBig() const;
    const std::string& getPictureXl() const;
};
