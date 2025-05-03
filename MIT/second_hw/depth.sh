#!/bin/bash
FILE_PATH=$(find . -name "how_far_are_you.txt" -type f)
D=$(echo "$FILE_PATH" | tr '/' '\n' | wc -l)
echo "$D"
