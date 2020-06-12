#pragma once

#include <string>

#include "models/Track.h"

class Deezer {
    std::string arl;

 public:
    Deezer() = default;
    Track getTrack(int id);
    void setArl(const std::string& arl);
};