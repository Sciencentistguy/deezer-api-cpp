#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

class User {
    int id;
    std::string name;
    std::string firstname;
    std::string lastname;
    std::string email;
    int status;
    //date birthday;
    //date inscription_date;
    std::string gender;
    std::string link;
    std::string picture;
    std::string picture_small;
    std::string picture_medium;
    std::string picture_big;
    std::string picture_xl;
    std::string country;
    std::string lang;
    bool kid;
    std::string explicit_content_level;
    std::vector<std::string> explicit_content_levels_available;
    std::string tracklist;
 public:
    explicit User(nlohmann::json user_json);
    int getId() const;
    const std::string& getName() const;
    const std::string& getFirstname() const;
    const std::string& getLastname() const;
    const std::string& getEmail() const;
    int getStatus() const;
    const std::string& getGender() const;
    const std::string& getLink() const;
    const std::string& getPicture() const;
    const std::string& getPictureSmall() const;
    const std::string& getPictureMedium() const;
    const std::string& getPictureBig() const;
    const std::string& getPictureXl() const;
    const std::string& getCountry() const;
    const std::string& getLang() const;
    bool isKid() const;
    const std::string& getExplicitContentLevel() const;
    const std::vector<std::string>& getExplicitContentLevelsAvailable() const;
    const std::string& getTracklist() const;
};
