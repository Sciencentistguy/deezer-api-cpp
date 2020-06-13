#pragma once

#include <string>

#include "models/album.h"
#include "models/artist.h"
#include "models/genre.h"
#include "models/track.h"
#include "models/user.h"

class Deezer {
    std::string arl;

 public:
    Deezer() = default;
    Track getTrack(int id);
    void setArl(const std::string& arl);
    Album getAlbum(int id);
    Artist getArtist(int id);
    Genre getGenre(int id);
    User getUser(int id);
};