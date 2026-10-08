#include "httplib.h"
#include "html.cpp"

int main() {
    // HTTP
    httplib::Server server;

    // HTTPS
    //httplib::SSLServer svr;

    server.Get("/game", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(html_game::html_game, "text/html");
    });

    server.Get("/prism", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(html_game::html_prism, "text/html");
    });

    server.Get("/", [](const httplib::Request &, httplib::Response &res) {
        res.set_redirect("/game", 301);
    });

    server.listen("0.0.0.0", 80);

    return 0;
}
