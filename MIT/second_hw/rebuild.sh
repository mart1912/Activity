#!/bin/bash
SOURCE_FILE="main.cpp"
OUTPUT_FILE="main"
echo "$SOURCE_FILE" | entr -p -s "g++ $SOURCE_FILE -o $OUTPUT_FILE && echo 'Перекомпиляция завершена.'"
