//
// Created by jamie on 6/13/20.
//

#include "user.h"
User::User(nlohmann::json user_json) :
    id{user_json.value("id", 0)}, name{user_json.value("name", "")}, firstname{user_json.value("firstname", "")}, lastname{user_json.value("lastname", "")},
    email{user_json.value("email", "")}, status{user_json.value("status", 0)}, gender{user_json.value("gender", "")}, link{user_json.value("link", "")},
    picture{user_json.value("picture", "")}, picture_small{user_json.value("picture_small", picture)}, picture_medium{user_json.value("picture_medium",
                                                                                                                                      picture)},
    picture_big{user_json.value("picture_big", picture)}, picture_xl{user_json.value("picture_xl", picture)}, country{user_json.value("country", "")},
    lang{user_json.value("lang", "")}, kid{user_json.value("is_kid", false)}, explicit_content_level{user_json.value("explicit_content_level", "")},
    explicit_content_levels_available{user_json.value("explicit_content_levels_available", std::vector<std::string>())}, tracklist{user_json.value(
                                                                                                                             "tracklist", "")} {
}
int User::getId() const {
    return id;
}
const std::string& User::getName() const {
    return name;
}
const std::string& User::getFirstname() const {
    return firstname;
}
const std::string& User::getLastname() const {
    return lastname;
}
const std::string& User::getEmail() const {
    return email;
}
int User::getStatus() const {
    return status;
}
const std::string& User::getGender() const {
    return gender;
}
const std::string& User::getLink() const {
    return link;
}
const std::string& User::getPicture() const {
    return picture;
}
const std::string& User::getPictureSmall() const {
    return picture_small;
}
const std::string& User::getPictureMedium() const {
    return picture_medium;
}
const std::string& User::getPictureBig() const {
    return picture_big;
}
const std::string& User::getPictureXl() const {
    return picture_xl;
}
const std::string& User::getCountry() const {
    return country;
}
const std::string& User::getLang() const {
    return lang;
}
bool User::isKid() const {
    return kid;
}
const std::string& User::getExplicitContentLevel() const {
    return explicit_content_level;
}
const std::vector<std::string>& User::getExplicitContentLevelsAvailable() const {
    return explicit_content_levels_available;
}
const std::string& User::getTracklist() const {
    return tracklist;
}
