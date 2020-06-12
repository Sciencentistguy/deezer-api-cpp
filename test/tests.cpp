#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include <Deezer.h>

#include "../src/utils/curl_utils.h"
#include "gtest/gtest.h"

TEST(DeezerApiCppTest, testCURL) {
    // This example is from the deezer web api documentation, so I'm trusting that it won't change
    const auto data = deezerApiRequest("user/2529");
    const auto matchData =
        R"({"id":2529,"name":"dadbond","link":"https:\/\/www.deezer.com\/profile\/2529","picture":"https:\/\/api.deezer.com\/user\/2529\/image","picture_small":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/56x56-000000-80-0-0.jpg","picture_medium":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/250x250-000000-80-0-0.jpg","picture_big":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/500x500-000000-80-0-0.jpg","picture_xl":"https:\/\/e-cdns-images.dzcdn.net\/images\/user\/35b2a990ccc09d4d0e90390484d221e3\/1000x1000-000000-80-0-0.jpg","country":"FR","tracklist":"https:\/\/api.deezer.com\/user\/2529\/flow","type":"user"})"_json;
    EXPECT_EQ(data["id"], matchData["id"]);
}

TEST(DeezerApiCppTest, testGetTrack) {
    // This test is "Harder, Better, Faster, Stronger" by Daft Punk (the example provided on the api documentation)
    Deezer d{};
    const auto track = d.getTrack(3135556);

    /*
     * Cannot test:
     * getShare() - This changes every time the API is hit.
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
}

#pragma clang diagnostic pop