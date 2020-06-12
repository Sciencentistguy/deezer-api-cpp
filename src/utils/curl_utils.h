#pragma once

#include <iostream>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "curl_exception.h"

constexpr auto USER_AGENT_HEADER = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36";

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);

std::string replaceAll(std::string str, const std::string& from, const std::string& to);

nlohmann::json deezerCurlInternal(const std::string& request, const std::string& endpoint, const std::map<std::string, std::string>& options,
                                  const std::string& authToken, const std::string& body);

nlohmann::json deezerApiRequest(const std::string& endpoint);