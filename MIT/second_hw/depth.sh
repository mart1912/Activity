#!/bin/bash
find . -name "how_far_are_you.txt" | sed 's|./||' | grep -o '/' | wc -l
