FROM ubuntu:22.04@sha256:bbf3d1baa208b7649d1d0264ef7d522e1dc0deeeaaf6085bf8e4618867f03494

RUN apt-get update && \
    apt-get install -y xinetd dumb-init

RUN useradd -m ctf

WORKDIR /home/ctf

RUN cp -R /lib /home/ctf && \
    cp -R /lib32 /home/ctf && \
    cp -R /lib64 /home/ctf && \
    cp -R /libx32 /home/ctf

RUN mkdir -p /home/ctf/usr && \
    cp -R /usr/lib /home/ctf/usr/lib && \
    cp -R /usr/lib32 /home/ctf/usr/lib32 && \
    cp -R /usr/lib64 /home/ctf/usr/lib64 && \
    cp -R /usr/libx32 /home/ctf/usr/libx32

RUN mkdir /home/ctf/dev && \
    mknod /home/ctf/dev/null c 1 3 && \
    mknod /home/ctf/dev/zero c 1 5 && \
    mknod /home/ctf/dev/random c 1 8 && \
    mknod /home/ctf/dev/urandom c 1 9

RUN mkdir /home/ctf/bin && \
    cp /bin/sh /home/ctf/bin && \
    cp /bin/ls /home/ctf/bin && \
    cp /bin/cat /home/ctf/bin && \
    cp /usr/bin/timeout /home/ctf/bin

COPY ./config/ctf.xinetd /etc/xinetd.d/ctf
COPY ./config/start.sh /start.sh
RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN chmod +x /start.sh

COPY ./release/chall /home/ctf/pwn
COPY ./config/flag.txt /home/ctf/flag.txt

RUN chown -R root:ctf /home/ctf && \
    chmod -R 740 /home/ctf/* && \
    chmod -R 750 /home/ctf/lib* && \
    chmod -R 750 /home/ctf/bin && \
    chmod -R 750 /home/ctf/usr && \
    chmod -R 750 /home/ctf/dev && \
    chmod 666 /home/ctf/dev/* && \
    chmod 750 /home/ctf/pwn && \
    chmod 540 /home/ctf/flag.txt

CMD ["dumb-init", "--", "/start.sh"]
