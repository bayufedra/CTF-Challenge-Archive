FROM python:3.8-slim

RUN apt-get update
RUN apt-get install -y nano socat gcc libgmp3-dev
RUN pip install fastecdsa

WORKDIR /opt

COPY . .

CMD socat TCP-LISTEN:5000,fork,reuseaddr EXEC:'python3 challenge.py'