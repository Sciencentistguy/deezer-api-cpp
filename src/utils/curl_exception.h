#pragma once

#include <exception>
#include <sstream>

class CurlException : public std::exception {
 public:
    explicit CurlException(int errorCode) : errorCode{errorCode} {
    }

    [[nodiscard]] const char* what() const noexcept override {
        static std::string message = "cURL error: " + std::to_string(errorCode);
        return message.c_str();
    }

 private:
    int errorCode;
};
