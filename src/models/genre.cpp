//
// Created by jamie on 6/13/20.
//

#include "genre.h"
Genre::Genre(nlohmann::json genre_json) :
    id{genre_json.value("id", 0)}, name{genre_json.value("name", "")}, picture{genre_json.value("picture", "")},
    picture_small{genre_json.value("picture_small", picture)}, picture_medium{genre_json.value("picture_medium", picture)},
    picture_big{genre_json.value("picture_big", picture)}, picture_xl{genre_json.value("picture_xl", picture)} {
}
int Genre::getId() const {
    return id;
}
const std::string& Genre::getName() const {
    return name;
}
const std::string& Genre::getPicture() const {
    return picture;
}
const std::string& Genre::getPictureSmall() const {
    return picture_small;
}
const std::string& Genre::getPictureMedium() const {
    return picture_medium;
}
const std::string& Genre::getPictureBig() const {
    return picture_big;
}
const std::string& Genre::getPictureXl() const {
    return picture_xl;
}
