#!/bin/bash
echo "🚀 Starting MiniKube..."
minikube start

echo "📦 Uploading images to Minikube..."
minikube image load go-cpp-worker-metrics-go-api:latest
minikube image load go-cpp-worker-metrics-cpp-worker:latest

echo "⚙️ Deploying apps..."
cd k8s
kubectl apply -f .

echo "⏳ Waiting for the start..."
sleep 3

echo "✅ Ready! Here the services:"
kubectl get services
echo ""
echo "🌐 Go API service:"
minikube service go-api-service --url
echo "🌐 CPP Worker service: "
minikube service cpp-worker-service --url