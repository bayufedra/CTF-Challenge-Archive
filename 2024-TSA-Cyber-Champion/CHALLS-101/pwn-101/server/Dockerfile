FROM ubuntu:latest

ENV PORT=20001
RUN apt-get update && apt-get -y install socat gcc gcc-multilib

COPY pwn .
COPY flag_2d2de462ebe19a876eb74b1c9c053120.txt /
EXPOSE ${PORT}
RUN chmod 555 pwn
USER nobody

CMD socat -v tcp-l:${PORT},reuseaddr,fork exec:'./pwn'
