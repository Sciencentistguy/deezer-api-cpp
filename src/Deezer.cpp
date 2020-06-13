#include "Deezer.h"

#include <string>

#include <utils/curl_utils.h>
void Deezer::setArl(const std::string& arl) {
    Deezer::arl = arl;
}

Track Deezer::getTrack(int id) {
    auto json = deezerApiRequest("track/" + std::to_string(id));
    return Track(json);
}

Album Deezer::getAlbum(int id) {
    auto json = deezerApiRequest("album/" + std::to_string(id));
    return Album(json);
}
