package main

import (
	"api/internal/routes"
	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Use(gin.Logger())
	r.Use(gin.Recovery())

	r.GET("/metrics", routes.GetMetrics)

	println("Server is running on port http://localhost:8080")
	r.Run(":8080")
}
