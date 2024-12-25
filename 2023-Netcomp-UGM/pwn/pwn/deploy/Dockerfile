FROM ubuntu:20.04

# Install some libs
RUN apt-get update && apt-get -y upgrade && apt-get -y install python socat
RUN apt-get install -y lib32z1 libseccomp-dev

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

#add chall items
#ADD chall_init.sh /etc/chall_init.sh
COPY flag /home/ctf/flag
COPY main /home/ctf/main
# ADD redir.sh /home/ctf/redir.sh

#set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/main
RUN chmod 440 /home/ctf/flag

USER ctf
# COPY challenge.py .
CMD socat TCP-LISTEN:2022,reuseaddr,fork EXEC:"./main"
