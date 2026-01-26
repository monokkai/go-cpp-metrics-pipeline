# PulseGate — пошаговая карта проекта (Go + C++ + Docker + Kubernetes + Prometheus)

> Формат: **чекбоксы + порядок**. Идёшь строго сверху вниз. Не прыгаешь.
> Это roadmap как у взрослого SWE, не туториал для джунов.

---

## 🧭 ЭТАП 0. МЕНТАЛЬНАЯ ПОДГОТОВКА (НЕ ПРОПУСКАТЬ)

* [ ] Понять цель проекта: **показать SWE-мышление, а не количество кода**
* [ ] Принять правило: *сначала локально → потом Docker → потом Kubernetes → потом Prometheus*
* [ ] Создать пустой GitHub-репозиторий

    * Название: `go-cpp-metrics-pipeline`
    * Description заполнить сразу

📎 Полезно:

* [https://roadmap.sh/backend](https://roadmap.sh/backend)

---

## 🗂️ ЭТАП 1. СТРУКТУРА ПРОЕКТА (СКЕЛЕТ)

* [x] Создать корневую папку проекта
* [x] Инициализировать git (`git init`)
* [x] Создать базовую структуру папок:

    * [x] `go-api/`
    * [x] `cpp-worker/`
    * [x] `k8s/`
    * [x] `prometheus/`
    * [x] `docs/`
* [x] Создать `README.md` (пока пустой)

📎 Смотреть:

* [https://github.com/golang-standards/project-layout](https://github.com/golang-standards/project-layout)

---

## 🟦 ЭТАП 2. GO API — БАЗА

### 2.1 Инициализация Go-проекта

* [ ] Установить версию Go (проверить `go version`)
* [ ] Инициализировать Go-модуль
* [ ] Создать `cmd/` и `internal/`
* [ ] Написать минимальный HTTP-сервер
* [ ] Запустить локально

📎 Смотреть:

* [https://go.dev/doc/tutorial/getting-started](https://go.dev/doc/tutorial/getting-started)
* [https://pkg.go.dev/net/http](https://pkg.go.dev/net/http)

---

### 2.2 Метрики в Go (Prometheus client)

* [ ] Подключить Prometheus Go client
* [ ] Создать `/metrics` endpoint
* [ ] Добавить 1–2 кастомные метрики (counter / gauge)
* [ ] Проверить `/metrics` в браузере

📎 Смотреть:

* [https://prometheus.io/docs/guides/go-application/](https://prometheus.io/docs/guides/go-application/)

---

## 🟥 ЭТАП 3. C++ WORKER — БАЗА

### 3.1 Структура и сборка

* [ ] Установить CMake
* [ ] Создать `src/` папку
* [ ] Создать `CMakeLists.txt`
* [ ] Написать минимальный `main.cpp`
* [ ] Собрать бинарник локально

📎 Смотреть:

* [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

### 3.2 Метрики в C++

* [ ] Подключить `prometheus-cpp`
* [ ] Создать HTTP endpoint для метрик
* [ ] Добавить 1 counter или histogram
* [ ] Проверить `/metrics`

📎 Смотреть:

* [https://github.com/jupp0r/prometheus-cpp](https://github.com/jupp0r/prometheus-cpp)

---

## 🐳 ЭТАП 4. DOCKER (СНАЧАЛА БЕЗ K8S)

### 4.1 Docker для Go

* [ ] Создать Dockerfile
* [ ] Использовать multi-stage build
* [ ] Собрать образ
* [ ] Запустить контейнер
* [ ] Проверить `/metrics`

📎 Смотреть:

* [https://docs.docker.com/build/building/multi-stage/](https://docs.docker.com/build/building/multi-stage/)

---

### 4.2 Docker для C++

* [ ] Создать Dockerfile
* [ ] Multi-stage build (build → runtime)
* [ ] Собрать образ
* [ ] Запустить контейнер
* [ ] Проверить `/metrics`

📎 Смотреть:

* [https://docs.docker.com/language/cpp/](https://docs.docker.com/language/cpp/)

---

## ☸️ ЭТАП 5. KUBERNETES (LOCAL CLUSTER)

### 5.1 Подготовка

* [ ] Проверить `kubectl version`
* [ ] Проверить кластер (kind / minikube)
* [ ] Загрузить Docker-образы в кластер

📎 Смотреть:

* [https://kind.sigs.k8s.io/docs/user/quick-start/](https://kind.sigs.k8s.io/docs/user/quick-start/)
* [https://minikube.sigs.k8s.io/docs/start/](https://minikube.sigs.k8s.io/docs/start/)

---

### 5.2 Deployment + Service

* [ ] Deployment для Go API
* [ ] Service для Go API
* [ ] Deployment для C++ worker
* [ ] Service для C++ worker
* [ ] Проверить Pods
* [ ] Сделать port-forward

📎 Смотреть:

* [https://kubernetes.io/docs/concepts/workloads/controllers/deployment/](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)
* [https://kubernetes.io/docs/concepts/services-networking/service/](https://kubernetes.io/docs/concepts/services-networking/service/)

---

## 📊 ЭТАП 6. PROMETHEUS

### 6.1 Установка

* [ ] Установить Helm
* [ ] Добавить Prometheus Helm repo
* [ ] Установить Prometheus в кластер

📎 Смотреть:

* [https://prometheus-community.github.io/helm-charts](https://prometheus-community.github.io/helm-charts)

---

### 6.2 Сбор метрик

* [ ] Настроить scrape для Go API
* [ ] Настроить scrape для C++ worker
* [ ] Проверить Targets в Prometheus UI
* [ ] Выполнить 1–2 PromQL запроса

📎 Смотреть:

* [https://prometheus.io/docs/prometheus/latest/configuration/configuration/](https://prometheus.io/docs/prometheus/latest/configuration/configuration/)
* [https://prometheus.io/docs/prometheus/latest/querying/basics/](https://prometheus.io/docs/prometheus/latest/querying/basics/)

---

## 🧪 ЭТАП 7. ПРОВЕРКА И ОТЛАДКА

* [ ] Проверить логи pod-ов
* [ ] Убить pod и проверить рестарт
* [ ] Проверить метрики после рестарта

📎 Смотреть:

* [https://kubernetes.io/docs/tasks/debug/](https://kubernetes.io/docs/tasks/debug/)

---

## 📝 ЭТАП 8. README (ОЧЕНЬ ВАЖНО)

* [ ] Описание проекта
* [ ] Architecture diagram (ASCII или картинка)
* [ ] Tech stack
* [ ] Как запустить
* [ ] Что бы улучшил дальше

📎 Смотреть:

* [https://github.com/matiassingers/awesome-readme](https://github.com/matiassingers/awesome-readme)

---

## 🏁 ФИНАЛЬНЫЙ ЧЕК

* [ ] Проект запускается одной командой
* [ ] Метрики видны в Prometheus
* [ ] README выглядит как у internal tool
* [ ] Репозиторий не стыдно показать на собесе

---

## 🚀 ДОПОЛНИТЕЛЬНО (ПО ЖЕЛАНИЮ)

* [ ] Grafana
* [ ] gRPC между Go и C++
* [ ] Horizontal Pod Autoscaler
* [ ] Load testing

📎 Смотреть:

* [https://grafana.com/docs/](https://grafana.com/docs/)
* [https://kubernetes.io/docs/tasks/run-application/horizontal-pod-autoscale/](https://kubernetes.io/docs/tasks/run-application/horizontal-pod-autoscale/)

---

💡 **Если ты прошёл всё до конца — ты уже Middle SWE по мышлению.**
