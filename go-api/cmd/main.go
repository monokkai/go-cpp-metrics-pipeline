package main

import (
	"api/internal/routes"
	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Use(gin.Logger())
	r.Use(gin.Recovery())

	r.GET("/", routes.MetricsHandler)
	r.GET("/metrics", routes.ProxyToServiceHandler)
	r.GET("/health", routes.GetHealthService)

	println("Server is running on port http://localhost:8080")
	println("C++ metrics available at: http://localhost:3000/metrics")
	r.Run(":8080")
}
