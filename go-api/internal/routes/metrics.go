package routes

import (
	"github.com/gin-gonic/gin"
	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
	"github.com/prometheus/client_golang/prometheus/promhttp"
	"time"
)

type Metrics struct {
	opsProcessed prometheus.Counter
}

func newMetrics(reg prometheus.Registerer) *Metrics {
	m := &Metrics{
		opsProcessed: promauto.With(reg).NewCounter(prometheus.CounterOpts{
			Name: "go-cpp-worker-metrics",
			Help: "The total number of processed events",
		}),
	}

	return m
}

func recordMetrics(m *Metrics) {
	go func() {
		for {
			m.opsProcessed.Inc()
			time.Sleep(2 * time.Second)
		}
	}()
}

func MetricsHandler(c *gin.Context) {
	reg := prometheus.NewRegistry()
	reg.MustRegister(prometheus.NewGoCollector(), prometheus.NewProcessCollector(prometheus.ProcessCollectorOpts{}))

	m := newMetrics(reg)
	recordMetrics(m)

	handler := promhttp.HandlerFor(reg, promhttp.HandlerOpts{})
	handler.ServeHTTP(c.Writer, c.Request)
}
