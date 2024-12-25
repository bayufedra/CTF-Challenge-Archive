FROM golang:latest

EXPOSE 5000

RUN apt update && apt upgrade -y && apt update --fix-missing
RUN apt install nano socat -y

WORKDIR /app

COPY . .

RUN go mod download

RUN go build -o challenge

CMD socat TCP-LISTEN:5000,reuseaddr,fork EXEC:"./challenge"