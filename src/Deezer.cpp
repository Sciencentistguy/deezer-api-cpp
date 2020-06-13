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
Artist Deezer::getArtist(int id) {
    auto json = deezerApiRequest("artist/" + std::to_string(id));
    return Artist(json);
}
Genre Deezer::getGenre(int id) {
    auto json = deezerApiRequest("genre/" + std::to_string(id));
    return Genre(json);
}
