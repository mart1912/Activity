#!/bin/bash
S=$(find ~ -type f 2>/dev/null | fzf --height 40% --reverse --prompt="Выберите файл: ")
nano "$S"
