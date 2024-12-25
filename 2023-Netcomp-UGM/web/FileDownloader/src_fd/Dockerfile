FROM php:8.2-apache

RUN apt update && apt install cron -y

WORKDIR /var/www/html

COPY src/ .

RUN mkdir -p /var/www/html/download/temp
RUN chmod 777 -R /var/www/html/download/temp

COPY flag.txt /flag.txt
RUN mv /flag.txt /flag-$(cat /dev/urandom | tr -dc '[:alpha:]' | fold -w ${1:-20} | head -n 1).txt

RUN (crontab -l ; echo "*/5 * * * * rm -rf /var/www/html/download/temp/*") | crontab

EXPOSE 80

CMD service cron start && apache2-foreground