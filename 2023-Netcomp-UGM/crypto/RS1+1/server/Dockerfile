FROM python:3.9-slim-buster

RUN apt-get update -y
RUN apt-get install socat -y

WORKDIR /app
COPY app/ /app
RUN pip install --no-cache-dir -r requirements.txt
RUN chmod +x chall.py

RUN groupadd ctf
RUN useradd ctf -g ctf
USER ctf

EXPOSE 5000
CMD socat TCP-LISTEN:5000,reuseaddr,fork EXEC:./chall.py
