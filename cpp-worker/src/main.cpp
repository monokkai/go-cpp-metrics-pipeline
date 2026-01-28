//
// Created by Diegø Måyer on 26/1/26.
//

#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

#include <array>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

int main() {
    using namespace prometheus;

    std::cout << "Starting Prometheus metrics server on http://localhost:3000/metrics" << std::endl;

    Exposer exposer{"0.0.0.0:3000"};
    auto registry = std::make_shared<Registry>();

    auto &counter = BuildCounter()
            .Name("cpp_requests_total")
            .Help("Total requests")
            .Register(*registry)
            .Add({});

    auto &packet_counter = BuildCounter()
            .Name("observed_packets_total")
            .Help("Number of observed packets")
            .Register(*registry);

    auto &tcp_rx_counter =
            packet_counter.Add({{"protocol", "tcp"}, {"direction", "rx"}});
    auto &tcp_tx_counter =
            packet_counter.Add({{"protocol", "tcp"}, {"direction", "tx"}});
    auto &udp_rx_counter =
            packet_counter.Add({{"protocol", "udp"}, {"direction", "rx"}});
    auto &udp_tx_counter =
            packet_counter.Add({{"protocol", "udp"}, {"direction", "tx"}});

    auto &http_requests_counter = BuildCounter()
            .Name("http_requests_total")
            .Help("Number of HTTP requests")
            .Register(*registry);

    counter.Increment();

    exposer.RegisterCollectable(registry);


    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        const auto random_value = std::rand();

        if (random_value & 1) tcp_rx_counter.Increment();
        if (random_value & 2) tcp_tx_counter.Increment();
        if (random_value & 4) udp_rx_counter.Increment();
        if (random_value & 8) udp_tx_counter.Increment();

        const std::array<std::string, 4> methods = {"GET", "PUT", "POST", "HEAD"};
        auto method = methods.at(random_value % methods.size());
        http_requests_counter.Add({{"method", method}}).Increment();
    }

    return 0;
}
