#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include <chrono>

#include <Deezer.h>

#include "../src/utils/curl_utils.h"
#include "gtest/gtest.h"

TEST(DeezerApiCppTest, testCURL) {
    // This example is from the deezer api documentation, so I'm trusting that it won't change
    auto start{std::chrono::high_resolution_clock::now()};
    const auto data = deezerApiRequest("user/2529");
    auto finish{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "cURL request took " << elapsed.count() << " seconds.";

    const auto matchData =
        R"({"id":2529,"name":"dadbond","link":"https:\/\/www.deezer.com\/profile\/2529","picture":"https:\/\/api.deezer.com\/user\/2529\/image","picture_small":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/56x56-000000-80-0-0.jpg","picture_medium":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/250x250-000000-80-0-0.jpg","picture_big":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/500x500-000000-80-0-0.jpg","picture_xl":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/1000x1000-000000-80-0-0.jpg","country":"FR","tracklist":"https:\/\/api.deezer.com\/user\/2529\/flow","type":"user"})"_json;
    EXPECT_EQ(data["id"], matchData["id"]);
}

TEST(DeezerApiCppTest, testGetTrack) {
    // This test is "Harder, Better, Faster, Stronger" by Daft Punk (the example provided on the api documentation)
    auto start{std::chrono::high_resolution_clock::now()};
    Deezer d{};
    const auto track = d.getTrack(3135556);
    auto finish{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Track request + parse took " << elapsed.count() << " seconds.";

    /*
     * Cannot test:
     * getShare() - This can change.
     */
    EXPECT_EQ(track.getTitle(), "Harder, Better, Faster, Stronger");
    EXPECT_EQ(track.getTitleShort(), "Harder, Better, Faster, Stronger");
    EXPECT_EQ(track.getTitleVersion(), "");
    EXPECT_EQ(track.getIsrc(), "GBDUW0000059");
    EXPECT_EQ(track.getLink(), "https://www.deezer.com/track/3135556");
    EXPECT_EQ(track.getDuration(), 224);
    EXPECT_EQ(track.getTrackPosition(), 4);
    EXPECT_EQ(track.getDiscNumber(), 1);
    EXPECT_NE(track.getRank(), 0);
    EXPECT_EQ(track.isExplicitLyrics(), false);
    EXPECT_EQ(track.getExplicitContentLyrics(), 0);
    EXPECT_EQ(track.getExplicitContentCover(), 0);
    EXPECT_EQ(track.getBpm(), 123.4);
    EXPECT_EQ(track.getGain(), -12.4);

    const std::vector<std::string> matchAvailableCountries = {
        "AE", "AF", "AG", "AI", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AU", "AZ", "BA", "BB", "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BN", "BO",
        "BQ", "BR", "BT", "BV", "BW", "BY", "CA", "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CV", "CW", "CX", "CY", "CZ",
        "DE", "DJ", "DK", "DM", "DZ", "EC", "EE", "EG", "EH", "ER", "ES", "ET", "FI", "FJ", "FK", "FM", "FR", "GA", "GB", "GD", "GE", "GH", "GM", "GN",
        "GQ", "GR", "GS", "GT", "GU", "GW", "HK", "HM", "HN", "HR", "HU", "ID", "IE", "IL", "IN", "IO", "IQ", "IS", "IT", "JM", "JO", "JP", "KE", "KG",
        "KH", "KI", "KM", "KN", "KR", "KW", "KY", "KZ", "LA", "LB", "LC", "LK", "LR", "LS", "LT", "LU", "LV", "LY", "MA", "MD", "ME", "MG", "MH", "MK",
        "ML", "MM", "MN", "MP", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ", "NA", "NE", "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ",
        "OM", "PA", "PE", "PG", "PH", "PK", "PL", "PN", "PS", "PT", "PW", "PY", "QA", "RO", "RS", "RU", "RW", "SA", "SB", "SC", "SD", "SE", "SG", "SI",
        "SJ", "SK", "SL", "SN", "SO", "SS", "ST", "SV", "SX", "SZ", "TC", "TD", "TG", "TH", "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TV", "TW", "TZ",
        "UA", "UG", "US", "UY", "UZ", "VC", "VE", "VG", "VI", "VN", "VU", "WS", "YE", "ZA", "ZM", "ZW"};

    EXPECT_EQ(track.getAvailableCountries(), matchAvailableCountries);

    EXPECT_EQ(track.getAlbum()->getId(), 302127);
    EXPECT_EQ(track.getArtist()->getId(), 27);
}

TEST(DeezerApiCppTest, testGetAlbum) {
    // This test is "Discovery" by Daft Punk. It is the example from the Deezer api documentation
    auto start{std::chrono::high_resolution_clock::now()};
    Deezer d;
    const auto album = d.getAlbum(302127);
    auto finish{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Album request + parse took " << elapsed.count() << " seconds.";

    /*
     * Cannot test:
     * getShare() - This can change.
     * getFans() - This can change.
     */
    EXPECT_EQ(album.getId(), 302127);
    EXPECT_EQ(album.getTitle(), "Discovery");
    EXPECT_EQ(album.getUpc(), "724384960650");
    EXPECT_EQ(album.getLink(), "https://www.deezer.com/album/302127");
    EXPECT_EQ(album.getCover(), "https://api.deezer.com/album/302127/image");
    EXPECT_EQ(album.getGenreId(), 113);
    EXPECT_EQ(album.getLabel(), "Parlophone (France)");
    EXPECT_EQ(album.getNbTracks(), 14);
    EXPECT_EQ(album.getDuration(), 3660);
    //    EXPECT_EQ(album.getFans(), 212365);
    EXPECT_EQ(album.getRating(), 0);
    EXPECT_EQ(album.getRecordType(), "album");
    EXPECT_EQ(album.isAvailable(), true);
    EXPECT_EQ(album.getTracklist(), "https://api.deezer.com/album/302127/tracks");
    EXPECT_EQ(album.isExplicitLyrics(), false);
    EXPECT_EQ(album.getExplicitContentLyrics(), 7);
    EXPECT_EQ(album.getExplicitContentCover(), 0);
    // contributors
    // artist

    EXPECT_EQ(album.getTracks()[0].getId(), 3135553);
    EXPECT_EQ(album.getTracks()[1].getId(), 3135554);
    EXPECT_EQ(album.getTracks()[2].getId(), 3135555);
    EXPECT_EQ(album.getTracks()[3].getId(), 3135556);
    EXPECT_EQ(album.getTracks()[4].getId(), 3135557);
    EXPECT_EQ(album.getTracks()[5].getId(), 3135558);
    EXPECT_EQ(album.getTracks()[6].getId(), 3135559);
    EXPECT_EQ(album.getTracks()[7].getId(), 3135560);
    EXPECT_EQ(album.getTracks()[8].getId(), 3135561);
    EXPECT_EQ(album.getTracks()[9].getId(), 3135562);
    EXPECT_EQ(album.getTracks()[10].getId(), 3135563);
    EXPECT_EQ(album.getTracks()[11].getId(), 3135564);
    EXPECT_EQ(album.getTracks()[12].getId(), 3135565);
    EXPECT_EQ(album.getTracks()[13].getId(), 3135566);

    EXPECT_EQ(album.getTracks()[0].getAlbum(), nullptr);

    EXPECT_EQ(album.getArtist()->getId(), 27);
    EXPECT_EQ(album.getContributors()[0].getId(), 27);

}

TEST(DeezerApiCppTest, testGetArtist) {
    // This test is "Daft Punk". It is the example from the Deezer api documentation
    auto start{std::chrono::high_resolution_clock::now()};
    Deezer d;
    auto artist = d.getArtist(27);
    auto finish{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Artist request + parse took " << elapsed.count() << " seconds.";

    /*
     * Cannot test:
     * getFans() - This can change
     */
    EXPECT_EQ(artist.getId(), 27);
    EXPECT_EQ(artist.getName(), "Daft Punk");
    EXPECT_EQ(artist.getLink(), "https://www.deezer.com/artist/27");
    EXPECT_EQ(artist.getPicture(), "https://api.deezer.com/artist/27/image");
    EXPECT_NE(artist.getNbAlbum(), 0);
    EXPECT_EQ(artist.isRadio(), true);
    EXPECT_EQ(artist.getTracklist(), "https://api.deezer.com/artist/27/top?limit=50");
}

TEST(DeezerApiCppTest, testGetGenre) {
    // This test isn't the example from the documentation, because that uses ID 0, which may allow the test to pass when the parsing failed.
    auto start{std::chrono::high_resolution_clock::now()};
    Deezer d;
    auto genre = d.getGenre(2);
    auto finish{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Genre request + parse took " << elapsed.count() << " seconds.";

    EXPECT_EQ(genre.getId(), 2);
    EXPECT_EQ(genre.getName(), "African Music");
    EXPECT_EQ(genre.getPicture(), "https://api.deezer.com/genre/2/image");

}
#pragma clang diagnostic pop