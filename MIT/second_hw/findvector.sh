#!/bin/bash
find / -type f -name "*.cpp" 2>/dev/null
if [[ -f "$file" ]] && grep -r "#include <vector>" "$file"; then
	echo "$file"
fi
