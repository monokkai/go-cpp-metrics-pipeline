package routes

import "github.com/gin-gonic/gin"

type Metrics struct {
	ID   int    `json:"id"`
	name string `json:"name"`
}

func GetMetrics(c *gin.Context) {
	c.JSON(200, gin.H{"metrics": "you got the info about /metrics"})
}
