#! /bin/sh

# Build script that should work on both macOS and linux

gcc -std=c11 \
    -Wall -Werror \
    -pedantic-errors \
    -march=native \
    -o main.out \
    -g \
    main.c
