#include <iostream>
#include <atomic>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <thread>

std::atomic<int> cpp_requests_total{0};
std::atomic<int> tcp_rx{0}, tcp_tx{0}, udp_rx{0}, udp_tx{0};

void handle(int client_sock) {
    char buffer[1024] = {0};
    read(client_sock, buffer, sizeof(buffer));

    std::string request(buffer);
    std::string response;

    if (request.find("/metrics") != std::string::npos) {
        cpp_requests_total++;

        std::stringstream ss;
        ss << "HTTP/1.1 200 OK\r\n"
           << "Content-Type: text/plain\r\n\r\n"
           << "# HELP cpp_requests_total Total requests\n"
           << "# TYPE cpp_requests_total counter\n"
           << "cpp_requests_total " << cpp_requests_total << "\n\n"
           << "# HELP observed_packets_total Number of packets\n"
           << "# TYPE observed_packets_total counter\n"
           << "observed_packets_total{protocol=\"tcp\",dir=\"rx\"} " << tcp_rx << "\n"
           << "observed_packets_total{protocol=\"tcp\",dir=\"tx\"} " << tcp_tx << "\n"
           << "observed_packets_total{protocol=\"udp\",dir=\"rx\"} " << udp_rx << "\n"
           << "observed_packets_total{protocol=\"udp\",dir=\"tx\"} " << udp_tx << "\n";
        response = ss.str();
    } else {
        response = "HTTP/1.1 200 OK\r\n\r\nC++ Metrics Server\n/metrics - metrics\n";
    }

    send(client_sock, response.c_str(), response.size(), 0);
    close(client_sock);
}

int main() {
    srand(time(nullptr));

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(3000);

    bind(sock, (sockaddr*)&addr, sizeof(addr));
    listen(sock, 5);

    std::cout << "Server: http://localhost:3000/metrics\n";

    std::thread([](){
        while(1) {
            sleep(1);
            tcp_rx += rand()%3; tcp_tx += rand()%2;
            udp_rx += rand()%4; udp_tx += rand()%2;
        }
    }).detach();

    while(1) {
        int client = accept(sock, nullptr, nullptr);
        if(client > 0) handle(client);
    }
}