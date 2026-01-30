FROM golang:1.24-alpine AS builder

WORKDIR /app

RUN apk add --no-cache git

COPY go-api/go.mod go-api/go.sum ./
RUN go mod download

COPY go-api/ .

RUN CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -o app ./cmd

FROM gcr.io/distroless/base-debian12

WORKDIR /app

COPY --from=builder /app/app /app/app

EXPOSE 8080

CMD ["/app/app"]