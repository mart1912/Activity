#!/bin/bash
ZIP_FILE="compressed.zip"
find project/ -type f -name "*.cpp" -exec zip -j "$ZIP_FILE" {} + > /dev/null
unzip -l compressed.zip
