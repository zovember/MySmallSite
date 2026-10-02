#include "httplib.h"
#include "html_game.cpp"

int main() {
    // HTTP
    httplib::Server server;

    // HTTPS
    //httplib::SSLServer svr;

    server.Get("/game", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(html_game::html_game, "text/html");
    });

    server.listen("0.0.0.0", 80);

    return 0;
}
