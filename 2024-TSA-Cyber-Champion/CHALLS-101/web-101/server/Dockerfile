FROM php:7.3-apache 

RUN apt-get update && apt-get install -y iputils-ping

# COPY php.ini /usr/local/etc/php
COPY app/ /var/www/html
RUN chmod 777 /var/www/html/uploads/

COPY flag_c7319b0bd96f9d01981bbf52ebb7027f.txt /
EXPOSE 80
