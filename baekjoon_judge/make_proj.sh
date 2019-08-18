#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage : ./make_proj.sh <problem number>"
  exit 0
fi

# make dir and basic code
mkdir -p "$1"
cd "$1"

# basic code
echo "#include <iostream>" >> "$1".cpp
echo "" >> "$1".cpp
echo "int main()" >> "$1".cpp
echo "{" >> "$1".cpp
echo "" >> "$1".cpp
echo "  return 0;" >> "$1".cpp
echo "}" >> "$1".cpp
