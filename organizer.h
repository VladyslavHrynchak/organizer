#ifndef ORGANIZER_H
#define ORGANIZER_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "nlohmann/json.hpp"


class Organizer
{
public:
    Organizer() = default;
    void start();

private:
    auto google_translator(const std::string& translate_to, const std::string& text);

    auto google_search(const std::string& text);

    auto google_news();

    auto weather();
};

#endif
