#!/bin/bash

HOST_PATH="$PWD"

CONTAINER_PATH="/home/testuser/workdir"

IMAGE_NAME="recoder-sudo"

if ! command -v docker &> /dev/null; then
    echo "Docker n'est pas installé. Veuillez l'installer avant de continuer."
    exit 1
fi

echo "Construction de l'image Docker à partir du Dockerfile dans le répertoire : $HOST_PATH"
docker build -t "$IMAGE_NAME" "$HOST_PATH"

if [ ! -d "$HOST_PATH" ]; then
    echo "Erreur : Le répertoire '$HOST_PATH' n'existe pas."
    exit 1
fi

docker run -it --rm \
  -v "$HOST_PATH:$CONTAINER_PATH" \
  -w "$CONTAINER_PATH" \
  --name test-sudo \
  $IMAGE_NAME

echo "Le répertoire '$HOST_PATH' a été monté dans le conteneur sous '$CONTAINER_PATH'."
