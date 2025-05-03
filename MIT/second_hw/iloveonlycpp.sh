#!/bin/bash
find . -type f ! \( -name "*.cpp" -o -name "*.sh" \) -exec rm -f {} +
find . -type d ! -name "." -exec rm -rf {} +
