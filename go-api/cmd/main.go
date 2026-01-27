package main

import (
	"api/internal/routes"
	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Use(gin.Logger())
	r.Use(gin.Recovery())

	r.GET("/", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"message": "This is the '/' base route!",
		})
	})
	r.GET("/metrics", routes.MetricsHandler)

	println("Server is running on port http://localhost:8080")
	r.Run(":8080")
}
