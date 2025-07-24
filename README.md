# Bishal Parajuli - Project 2

## Overview

This project is a simplified reimplementation of standard Unix utilities as part of the OSTEP course exercises:

- `my-cat` – Concatenate and display files.
- `my-grep` – Search for lines matching a pattern.
- `my-zip` – Compress files using run-length encoding (RLE).
- `my-unzip` – Decompress files encoded with RLE.

Each tool is written in C and tested using custom shell scripts and test files.

## Usage

### Compilation

```bash
gcc -Wall -Werror -o wcat my-cat.c
gcc -Wall -Werror -o wgrep my-grep.c
gcc -Wall -Werror -o wzip my-zip.c
gcc -Wall -Werror -o wunzip my-unzip.c
