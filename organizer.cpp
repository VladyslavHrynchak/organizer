#include "organizer.h"
#include <string>

using namespace std;

auto Organizer::google_translator(const string& translate_to, const string& text)
{
    httplib::Client cli("https://google-translate1.p.rapidapi.com");

    httplib::Headers headers;
    headers.emplace("X-RapidAPI-Host","google-translate1.p.rapidapi.com");
    headers.emplace("X-RapidAPI-Key","2706d55a79msh75873fce97b4bbfp1ec66djsnb0a83ecea38a");

    httplib::Params params;
    params.emplace( "source", "en" );
    params.emplace( "target", translate_to );
    params.emplace( "q", text );

    auto res = cli.Post("/language/translate/v2", headers ,params);

    auto a = nlohmann::json::parse(res->body);

    return a["data"]["translations"][0].dump(2) ;
}

auto Organizer::google_search(const std::string& text)
{
    httplib::Client cli("https://google-search3.p.rapidapi.com");

    httplib::Headers headers;
    headers.emplace("X-User-Agent","desktop");
    headers.emplace("X-Proxy-Location","EU");
    headers.emplace("X-RapidAPI-Host","google-search3.p.rapidapi.com");
    headers.emplace("X-RapidAPI-Key","2706d55a79msh75873fce97b4bbfp1ec66djsnb0a83ecea38a");

    httplib::Params params;
    params.emplace( "q", text );
    auto str = "/api/v1/search/q=" + text;
    auto res = cli.Get(str.c_str(), params,headers);

    auto a = nlohmann::json::parse(res->body);

    return a["results"][0].dump(2);

}

 auto Organizer::google_news()
 {
     httplib::Client cli("https://google-news1.p.rapidapi.com");

     httplib::Headers headers;
     headers.emplace("X-RapidAPI-Host","google-news1.p.rapidapi.com");
     headers.emplace("X-RapidAPI-Key","2706d55a79msh75873fce97b4bbfp1ec66djsnb0a83ecea38a");


     auto res = cli.Get("/top-headlines?country=US&lang=en&limit=50", {},headers);

     auto a = nlohmann::json::parse(res->body);

     return a["articles"].dump(2);
 }

void Organizer::start()
{
    int num;
    string translate_to, text,exit = "n";
    while(exit == "n")
    {
    cout << "Organizer started...." << endl;
    cout << "Enter num: " << endl;
    cout << "1 - translator from English" << endl;
    cout << "2 - google search" << endl;
    cout << "3 - google news" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "Enter the language to be translated: ";
        cin >> translate_to;
        cout << "Enter word: ";
        cin >> text;

       cout << google_translator(translate_to,text) << endl;

        break;
    case 2:
        cout << "Enter text to search: ";
        cin >> text;
        cout << google_search(text) << endl;

        break;
    case 3:

        cout << google_news()<< endl;

        break;

    default:
        break;
    }
    cout << "Enter 'n' to continue or 'y' to exit ";
    cin >> exit;

 }
}
