FROM alpine:latest

WORKDIR /app

RUN apk add --no-cache g++ musl-dev

COPY src/ .

RUN g++ -std=c++11 -O3 main.cpp -o cpp-server -pthread

EXPOSE 3000

CMD ["./cpp-server"]