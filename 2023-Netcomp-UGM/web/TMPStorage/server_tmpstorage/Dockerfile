FROM php:7.3-apache 
RUN docker-php-ext-install mysqli

COPY conf/php.ini /usr/local/etc/php
COPY conf/docker-php.conf /etc/apache2/conf-available/
COPY flag.txt /

RUN groupadd ctf
RUN useradd ctf -g ctf
USER ctf
