#Debian ARM64: buster
FROM hmacielp/crosscompile-gpio:latest

WORKDIR /workspace

COPY tools/entrypoint.sh /

RUN chmod +x /entrypoint.sh

COPY . .

ENTRYPOINT ["entrypoint.sh"]
