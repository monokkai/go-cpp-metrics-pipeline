# go-cpp-metrics-pipeline

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-17-blue)](https://isocpp.org/)
[![Go](https://img.shields.io/badge/Go-1.21-blue)](https://golang.org/)
[![Kubernetes](https://img.shields.io/badge/Kubernetes-1.28-blue)](https://kubernetes.io/)

A distributed metrics processing pipeline showcasing a polyglot architecture. The system uses a **Go service** for API management and orchestration, while a **C++ worker** handles compute-intensive metric aggregation. It is fully containerized, deployable on Kubernetes, and integrated with Prometheus for comprehensive observability.

## 📋 Overview

This project demonstrates a modern, scalable approach to processing metrics by combining the strengths of two powerful languages:
*   **Go**: Manages the API, request lifecycle, and orchestrates jobs. Its concurrency model is perfect for handling numerous simultaneous connections and coordinating tasks.
*   **C++**: Performs the heavy lifting for metric aggregation. Its high performance and efficiency are ideal for the computational core of the pipeline.

The entire stack is designed to run in containers, orchestrated by Kubernetes, and is observable via Prometheus metrics.

## 🏗️ Architecture

The system consists of two primary services:


1.  **Go API Service**: Located in the `go-api/` directory.
    *   Exposes REST endpoints for clients to submit processing requests or query status.
    *   Handles orchestration, potentially managing a queue of work for the C++ worker.
    *   Exposes its own operational metrics (e.g., request rates, latencies) for monitoring.

2.  **C++ Worker**: Located in the `cpp-worker/` directory.
    *   Performs the core, compute-heavy metric aggregation logic.
    *   Receives tasks from the Go service.
    *   Exports detailed performance and internal metrics (e.g., tasks processed, processing duration, memory usage) in Prometheus format.

## 🛠️ Technology Stack

*   **Core Languages**: Go (for API/orchestration), C++17 (for compute worker).
*   **Build Tools**: Go modules, CMake (for C++).
*   **Containerization**: Docker with multi-stage builds for optimized images.
*   **Orchestration**: Kubernetes with manifests for deployment, services, and configmaps (see `k8s/`).
*   **Observability**: Prometheus for metrics collection (`prometheus/`) and Grafana for visualization.
*   **Local Development**: Docker Compose for spinning up the entire stack locally (see `docker-compose.yml`).

## 🚀 Getting Started

### Prerequisites

*   [Go](https://golang.org/dl/) (version 1.21+)
*   [CMake](https://cmake.org/download/) (version 3.14+)
*   [Docker](https://docs.docker.com/get-docker/) and [Docker Compose](https://docs.docker.com/compose/install/)
*   [kubectl](https://kubernetes.io/docs/tasks/tools/) (for Kubernetes deployment)
*   (Optional) A Kubernetes cluster (e.g., [Minikube](https://minikube.sigs.k8s.io/docs/start/), [Kind](https://kind.sigs.k8s.io/))

### Local Development with Docker Compose

The easiest way to run the entire pipeline locally is using Docker Compose.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/monokkai/go-cpp-metrics-pipeline.git
    cd go-cpp-metrics-pipeline
    ```

2.  **Configure environment (optional):**
    Copy the example environment file and adjust variables as needed.
    ```bash
    cp .env.example .env
    ```

3.  **Build and run the stack:**
    ```bash
    docker-compose up --build
    ```
    This command builds the Go API and C++ worker images, and starts the services along with Prometheus and Grafana.

4.  **Access the services:**
    *   **Go API**: `http://localhost:8080`
    *   **C++ Worker Metrics**: `http://localhost:3000/metrics`
    *   **Prometheus**: `http://localhost:9090`
    *   **Grafana**: `http://localhost:3001` (default login: `admin`/`admin`)

### Kubernetes Deployment

Ready-to-use Kubernetes manifests are available in the `k8s/` directory. You can deploy them to your cluster:

```bash
kubectl apply -f k8s/
```

This will deploy the Go API, C++ worker, and necessary services. You may need to adjust the image names in the manifests to point to your own container registry.

## 📁 Repository Structure

```
.
├── .env.example          # Example environment variables
├── docker-compose.yml    # Local orchestration file
├── go-api/               # Source code for the Go API service
│   ├── cmd/
│   ├── internal/
│   └── Dockerfile
├── cpp-worker/           # Source code for the C++ worker
│   ├── src/
│   ├── CMakeLists.txt
│   └── Dockerfile
├── k8s/                  # Kubernetes deployment manifests
├── prometheus/           # Prometheus configuration
├── scripts/              # Helper scripts for building and running
└── README.md             # This file
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details (once added).
```
