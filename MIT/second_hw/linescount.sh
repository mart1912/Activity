#!/bin/bash
D=$(find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec cat {} + | wc -l)
echo "$D"
