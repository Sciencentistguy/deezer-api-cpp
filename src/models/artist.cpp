//
// Created by jamie on 6/13/20.
//

#include "artist.h"
Artist::Artist(nlohmann::json artist_json) :
    id{artist_json.value("id", 0)}, name{artist_json.value("name", "")}, link{artist_json.value("link", "")}, share{artist_json.value("share", "")},
    picture{artist_json.value("picture", "")}, picture_small{artist_json.value("picture_small", picture)}, picture_medium{artist_json.value("picture_medium",
                                                                                                                                            picture)},
    picture_big{artist_json.value("picture_big", picture)}, picture_xl{artist_json.value("picture", picture)}, nb_album{artist_json.value("nb_album", 0)},
    fans{artist_json.value("nb_fan", 0)}, radio{artist_json.value("radio", false)}, tracklist{artist_json.value("tracklist", "")} {
}
int Artist::getId() const {
    return id;
}
const std::string& Artist::getName() const {
    return name;
}
const std::string& Artist::getLink() const {
    return link;
}
const std::string& Artist::getShare() const {
    return share;
}
const std::string& Artist::getPicture() const {
    return picture;
}
const std::string& Artist::getPictureSmall() const {
    return picture_small;
}
const std::string& Artist::getPictureMedium() const {
    return picture_medium;
}
const std::string& Artist::getPictureBig() const {
    return picture_big;
}
const std::string& Artist::getPictureXl() const {
    return picture_xl;
}
int Artist::getNbAlbum() const {
    return nb_album;
}
int Artist::getFans() const {
    return fans;
}
bool Artist::isRadio() const {
    return radio;
}
const std::string& Artist::getTracklist() const {
    return tracklist;
}