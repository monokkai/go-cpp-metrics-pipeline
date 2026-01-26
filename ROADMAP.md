# PulseGate — Step-by-Step Project Roadmap (Go + C++ + Docker + Kubernetes + Prometheus)
---

## 🧭 STAGE 0. MENTAL PREPARATION (DO NOT SKIP)

* [x] Understand the goal of the project: **demonstrate SWE thinking, not amount of code**
* [x] Accept the rule: *local first → then Docker → then Kubernetes → then Prometheus*
* [x] Create an empty GitHub repository

    * Name: `go-cpp-metrics-pipeline`
    * Fill in the description immediately

📎 Useful:

* [https://roadmap.sh/backend](https://roadmap.sh/backend)

---

## 🗂️ STAGE 1. PROJECT STRUCTURE (SKELETON)

* [x] Create the project root directory
* [x] Initialize git (`git init`)
* [x] Create the base folder structure:

    * [x] `go-api/`
    * [x] `cpp-worker/`
    * [x] `k8s/`
    * [x] `prometheus/`
    * [x] `docs/`
* [x] Create `README.md` (empty for now)

📎 Reference:

* [https://github.com/golang-standards/project-layout](https://github.com/golang-standards/project-layout)

---

## 🟦 STAGE 2. GO API — FOUNDATION

### 2.1 Go project initialization

* [ ] Install Go and verify version (`go version`)
* [ ] Initialize Go module
* [ ] Create `cmd/` and `internal/`
* [ ] Implement a minimal HTTP server
* [ ] Run it locally

📎 Reference:

* [https://go.dev/doc/tutorial/getting-started](https://go.dev/doc/tutorial/getting-started)
* [https://pkg.go.dev/net/http](https://pkg.go.dev/net/http)

---

### 2.2 Metrics in Go (Prometheus client)

* [ ] Add Prometheus Go client
* [ ] Expose `/metrics` endpoint
* [ ] Add 1–2 custom metrics (counter / gauge)
* [ ] Verify `/metrics` in browser

📎 Reference:

* [https://prometheus.io/docs/guides/go-application/](https://prometheus.io/docs/guides/go-application/)

---

## 🟥 STAGE 3. C++ WORKER — FOUNDATION

### 3.1 Structure and build

* [ ] Install CMake
* [ ] Create `src/` directory
* [ ] Create `CMakeLists.txt`
* [ ] Implement minimal `main.cpp`
* [ ] Build binary locally

📎 Reference:

* [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

### 3.2 Metrics in C++

* [ ] Integrate `prometheus-cpp`
* [ ] Expose HTTP endpoint for metrics
* [ ] Add 1 counter or histogram
* [ ] Verify `/metrics`

📎 Reference:

* [https://github.com/jupp0r/prometheus-cpp](https://github.com/jupp0r/prometheus-cpp)

---

## 🐳 STAGE 4. DOCKER (WITHOUT K8S FIRST)

### 4.1 Docker for Go

* [ ] Create Dockerfile
* [ ] Use multi-stage build
* [ ] Build image
* [ ] Run container
* [ ] Verify `/metrics`

📎 Reference:

* [https://docs.docker.com/build/building/multi-stage/](https://docs.docker.com/build/building/multi-stage/)

---

### 4.2 Docker for C++

* [ ] Create Dockerfile
* [ ] Multi-stage build (build → runtime)
* [ ] Build image
* [ ] Run container
* [ ] Verify `/metrics`

📎 Reference:

* [https://docs.docker.com/language/cpp/](https://docs.docker.com/language/cpp/)

---

## ☸️ STAGE 5. KUBERNETES (LOCAL CLUSTER)

### 5.1 Preparation

* [ ] Verify `kubectl version`
* [ ] Verify cluster (kind / minikube)
* [ ] Load Docker images into the cluster

📎 Reference:

* [https://kind.sigs.k8s.io/docs/user/quick-start/](https://kind.sigs.k8s.io/docs/user/quick-start/)
* [https://minikube.sigs.k8s.io/docs/start/](https://minikube.sigs.k8s.io/docs/start/)

---

### 5.2 Deployment + Service

* [ ] Deployment for Go API
* [ ] Service for Go API
* [ ] Deployment for C++ worker
* [ ] Service for C++ worker
* [ ] Verify Pods
* [ ] Use port-forward

📎 Reference:

* [https://kubernetes.io/docs/concepts/workloads/controllers/deployment/](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)
* [https://kubernetes.io/docs/concepts/services-networking/service/](https://kubernetes.io/docs/concepts/services-networking/service/)

---

## 📊 STAGE 6. PROMETHEUS

### 6.1 Installation

* [ ] Install Helm
* [ ] Add Prometheus Helm repo
* [ ] Install Prometheus into the cluster

📎 Reference:

* [https://prometheus-community.github.io/helm-charts](https://prometheus-community.github.io/helm-charts)

---

### 6.2 Metrics scraping

* [ ] Configure scrape for Go API
* [ ] Configure scrape for C++ worker
* [ ] Verify Targets in Prometheus UI
* [ ] Execute 1–2 PromQL queries

📎 Reference:

* [https://prometheus.io/docs/prometheus/latest/configuration/configuration/](https://prometheus.io/docs/prometheus/latest/configuration/configuration/)
* [https://prometheus.io/docs/prometheus/latest/querying/basics/](https://prometheus.io/docs/prometheus/latest/querying/basics/)

---

## 🧪 STAGE 7. VERIFICATION AND DEBUGGING

* [ ] Check pod logs
* [ ] Kill a pod and verify restart
* [ ] Verify metrics after restart

📎 Reference:

* [https://kubernetes.io/docs/tasks/debug/](https://kubernetes.io/docs/tasks/debug/)

---

## 📝 STAGE 8. README (VERY IMPORTANT)

* [ ] Project description
* [ ] Architecture diagram (ASCII or image)
* [ ] Tech stack
* [ ] How to run
* [ ] Possible future improvements

📎 Reference:

* [https://github.com/matiassingers/awesome-readme](https://github.com/matiassingers/awesome-readme)

---

## 🏁 FINAL CHECK

* [ ] Project runs with a single command
* [ ] Metrics are visible in Prometheus
* [ ] README looks like an internal tool
* [ ] Repository is interview-ready

---

## 🚀 OPTIONAL (EXTRA)

* [ ] Grafana
* [ ] gRPC between Go and C++
* [ ] Horizontal Pod Autoscaler
* [ ] Load testing

📎 Reference:

* [https://grafana.com/docs/](https://grafana.com/docs/)
* [https://kubernetes.io/docs/tasks/run-application/horizontal-pod-autoscale/](https://kubernetes.io/docs/tasks/run-application/horizontal-pod-autoscale/)

---

💡 **If you complete everything — you already think like a Middle SWE.**
