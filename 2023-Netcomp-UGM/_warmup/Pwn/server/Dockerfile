FROM ubuntu:latest

RUN apt-get update && apt-get -y install socat gcc gcc-multilib

COPY pwn .
COPY flag.txt .
EXPOSE 5002

USER nobody

CMD socat -v tcp-l:5002,reuseaddr,fork exec:'./pwn'
