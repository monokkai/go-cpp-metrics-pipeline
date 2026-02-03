package main

import (
	"api/internal/routes"
	"github.com/gin-gonic/gin"
	"github.com/joho/godotenv"
	"log"
)

const (
	colorYellow = "\x1b[33m"
	colorBlue   = "\x1b[34m"
	colorReset  = "\x1b[0m"
)

func main() {
	if err := godotenv.Load(); err == nil {
		log.Fatal("Error loading .env file")
	}

	r := gin.Default()
	r.Use(gin.Logger())
	r.Use(gin.Recovery())

	r.GET("/", routes.MetricsHandler)
	r.GET("/metrics", routes.ProxyToServiceHandler)
	r.GET("/health", routes.GetHealthService)

	println(colorYellow + "Server is running on port http://localhost:8080" + colorReset)
	println(colorBlue + "C++ metrics available at: http://localhost:3000/metrics" + colorReset)
	r.Run(":8080")
}
