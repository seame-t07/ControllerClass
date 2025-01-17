#Debian ARM64: buster
FROM hmacielp/crosscompile-gpio:latest

WORKDIR /workspace

COPY . .

ENTRYPOINT ["entrypoint.sh"]
