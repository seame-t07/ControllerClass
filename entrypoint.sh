#!/bin/bash

# Verificar se o cmake está instalado
if ! command -v cmake &> /dev/null
then
    echo "CMake não está instalado. Instale-o antes de continuar."
    exit 1
fi

# Diretório do build
BUILD_DIR="build"

# Criar o diretório de build, se não existir
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Entrar no diretório de build
cd "$BUILD_DIR" || exit

# Executar o CMake para gerar os arquivos de build
echo "Gerando arquivos de configuração do CMake..."
cmake ..

# Verificar se a geração dos arquivos foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro ao gerar os arquivos de configuração do CMake."
    exit 1
fi

# Compilar o projeto
echo "Compilando o projeto..."
cmake --build .

# Verificar se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro durante a compilação."
    exit 1
fi

echo "Compilação concluída com sucesso."
