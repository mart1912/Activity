#!/bin/bash
find ~ -name '*.cpp' -printf '"%p"\n' | xargs grep -l '#include <vector>'
