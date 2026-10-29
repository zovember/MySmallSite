#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "httplib.h"
#include <iostream>

int main() {
    // HTTP
    httplib::Server server;

    // HTTPS
    //httplib::SSLServer server("/var/MySmallSite/cers/fullchain1.pem",
    //                          "/var/MySmallSite/cers/privkey1.pem");

    if (!server.is_valid()) {
        std::cout << "Cers Error\n";
        return -1;
    }

    std::cout << "Server has started\n";

    /*server.Get("/game", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(html_game::html_square, "text/html");
    });*/

    /*server.Get("/prism", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(html_game::html_prism, "text/html");
    });*/

    /*server.Get("/", [](const httplib::Request &, httplib::Response &res) {
        res.set_redirect("/game", 301);
    });*/


    server.Get("/key/dmxlc3M6", [](const httplib::Request &, httplib::Response &res) { // Я
        res.set_content("dmxlc3M6Ly8wZmI1OWM4Yy04OGFkLWJhMmQtNzA3Mi0wYzI5OGJhYjAxYmNAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5tZXRyb3BvbGlhLmZpJmZwPWZpcmVmb3gmcGJrPXVyZ0tFWUprZXptN3hBY0F0SDNXV25IeTBHMndWZ1J2eXFMWEZHc1YtU1Emc2lkPTI3ZTkwMGY4OTcxZTNmOWEmdHlwZT10Y3AmZmxvdz14dGxzLXJwcngtdmlzaW9uI1N1cGVyLU1lZ2EtQWRtaW4=", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly83O", [](const httplib::Request &, httplib::Response &res) { // Кирилл
        res.set_content("dmxlc3M6Ly83OWZmOWNhNS01Yjg2LTkyYTQtNjFlMi0yNzYxODQwOWMyODRAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNGaW5sYW5kLVNvcm9ja2luLUtpcmlsbA==", "text/plain");
    });

    server.Get("/key/MTo0NDM", [](const httplib::Request &, httplib::Response &res) { // Эдуард/Никита
        res.set_content("MTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNGaW5sYW5kLUhlbHNpbmtp", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly8wYjU", [](const httplib::Request &, httplib::Response &res) { // Бабушка
        res.set_content("dmxlc3M6Ly8wYjUxNmIxNC0wZjQ3LWEzMzMtOTIyZS1lYjQ4ZDhjNWViNjZAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNGaW5sYW5kLUdyYW5kbW90aGVyLU9sZ2E=", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly9iZj", [](const httplib::Request &, httplib::Response &res) { // Лера
        res.set_content("dmxlc3M6Ly9iZjI3ODA2NC1jY2Y0LTQwNTQtODZhMi00NTA5OTY4YzBiZjZAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNGaW5sYW5kLUhlbHNpbmtp", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly80NG", [](const httplib::Request &, httplib::Response &res) { // Саня, бывш Мотя
        res.set_content("dmxlc3M6Ly80NGIxY2E2OS01MDYxLTY1YWUtN2YzOS0xYjhkZmFmNmVmMTJAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNIZWxzaW5raS1NYXRWaWtv", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly9hNj", [](const httplib::Request &, httplib::Response &res) { // Данил
        res.set_content("dmxlc3M6Ly9hNjE2ZWRmYi02M2ZlLTRlNTgtODk4NS0wZThlNjZhYTQyNTdAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNIZWxzaW5raQ==", "text/plain");
    });

    server.Get("/key/dmxlc3M6Ly9iMj", [](const httplib::Request &, httplib::Response &res) { // CMP
        res.set_content("dmxlc3M6Ly9iMjIzYWNhNy1lOGFjLWVlZmUtYzRiYi1iYWE3MmMzMTMxNmZAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNGaW5sYW5kLUhlbHNpbmtp", "text/plain");
    });

    server.Get("/key", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("lox ;D", "text/plain");
    });

    server.Get("/key/MATVEY_LOX_MATVEY_L0X", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("dmxlc3M6Ly85YjZhMmJjYy04MTg0LTRmZTYtYWEzNi02YjJjYjA2ODAyYzlAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NWLVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNIZWxzaW5raS1NYXRWaWtv", "text/plain");
    });

    server.Get("/key/danilug6k00", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("dmxlc3M6Ly8wMDk4ZmU4OS1jZjE5LTQ2ZDQtYTE3Yy04NGJlYzRkNjkyODJAMTYzLjUuMTUzLjEwMTo0NDM/ZW5jcnlwdGlvbj1ub25lJnNlY3VyaXR5PXJlYWxpdHkmc25pPXd3dy5oZWxzaW5raS5maSZmcD1maXJlZm94JnBiaz11cmdLRVlKa2V6bTd4QWNBdEgzV1duSHkwRzJ3VmdSdnlxTFhGR3NW      LVNRJnNpZD0yN2U5MDBmODk3MWUzZjlhJnR5cGU9dGNwJmZsb3c9eHRscy1ycHJ4LXZpc2lvbiNIZWxzaW5raQo=", "text/plain");
    });


    server.listen("0.0.0.0", 1488);

    std::cout << "Server complited work\n";
    return 0;
}
