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

#pragma clang diagnostic pop