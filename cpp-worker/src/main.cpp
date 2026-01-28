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

    counter.Increment();

    exposer.RegisterCollectable(registry);

    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
