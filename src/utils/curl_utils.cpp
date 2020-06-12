#include <iostream>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "curl_exception.h"

constexpr auto USER_AGENT_HEADER = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36";

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    static_cast<std::string*>(userp)->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
    return str;
}

nlohmann::json deezerCurlInternal(const std::string& request, const std::string& endpoint, const std::map<std::string, std::string>& options,
                                  const std::string& authToken, const std::string& body) {
    CURL* curl;

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Could not initiate cURL" << std::endl;
        throw std::runtime_error("Could not initiate cURL");
    }

    std::string url = "https://api.deezer.com/" + endpoint;

    if (!options.empty()) {
        url += "?";
        for (const auto& option : options) {
            url += option.first + "=" + option.second + '&';
        }
    }
    url = replaceAll(url, " ", "%20");

    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request.c_str());

    std::string header = "User-Agent: " + std::string(USER_AGENT_HEADER);
    curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    if (!body.empty())
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        throw CurlException(rc);

    long statusCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);
    //    if (statusCode < 200 || statusCode > 204)
    //        throw spotify::SpotifyException(spotify::Error(nlohmann::json::parse(readBuffer)["error"]));

    curl_easy_cleanup(curl);
    if (readBuffer.empty())
        return nlohmann::json();
    return nlohmann::json::parse(readBuffer);
}

nlohmann::json deezerApiRequest(const std::string& endpoint) {
    const auto options = std::map<std::string, std::string>{};
    const auto arl = std::string{};
    const auto body = std::string{};
    return deezerCurlInternal("GET", endpoint, options, arl, body);
}