#Debian ARM64: buster
FROM hmacielp/crosscompile-gpio:latest

WORKDIR /workspace

COPY . .

RUN chmod +x ./tools/entrypoint.sh

ENTRYPOINT ["./tools/entrypoint.sh"]
