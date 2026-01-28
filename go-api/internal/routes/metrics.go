package routes

import (
	"github.com/gin-gonic/gin"
	"io"
	"net/http"
)

func MetricsHandler(c *gin.Context) {
	c.JSON(200, gin.H{
		"message":     "Go API Service",
		"cpp_metrics": "http://localhost:3000/metrics",
	})
}

func ProxyToServiceHandler(c *gin.Context) {
	resp, err := http.Get("http://localhost:3000/metrics")

	if err != nil {
		c.JSON(500, gin.H{
			"error": err.Error(),
		})
	}
	defer func(Body io.ReadCloser) {
		err := Body.Close()
		if err != nil {
			c.JSON(500, gin.H{
				"error": err.Error(),
			})
		}
	}(resp.Body)

	body, _ := io.ReadAll(resp.Body)
	c.Data(resp.StatusCode, resp.Header.Get("Content-Type"), body)
}

func GetHealthService(c *gin.Context) {
	_, err := http.Get("http://localhost:3000/metrics")

	if err != nil {
		c.JSON(503, gin.H{"status": "unhealthy", "cpp_worker": "down"})
		return
	}

	c.JSON(200, gin.H{
		"status":     "healthy",
		"cpp_worker": "up",
	})
}
