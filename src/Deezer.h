#pragma once

#include <string>

#include "models/album.h"
#include "models/track.h"

class Deezer {
    std::string arl;

 public:
    Deezer() = default;
    Track getTrack(int id);
    void setArl(const std::string& arl);
    Album getAlbum(int id);
};