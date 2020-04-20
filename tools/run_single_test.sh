#!/bin/bash

if (($# != 1)); then
    echo './run_single_test.sh <testName>'
    exit 1
fi

set -e

mkdir -p .tmp

echo "Running the test $1..."
echo "Compiling $1.cpp..."
g++ "tests/$1.cpp" -o ".tmp/$1" -Wall -Wshadow -Wextra -Werror -std=c++11 -I "headers"
echo "Compiling $1_gen.cpp..."
g++ "tests/$1_gen.cpp" -o ".tmp/$1_gen" -std=c++11 -I third_party/Tree-Generator
echo "Compiling $1_bf.cpp..."
g++ "tests/$1_bf.cpp" -o ".tmp/$1_bf" -std=c++11
echo "Compiling $1_check.cpp..."
g++ "tests/$1_check.cpp" -o ".tmp/$1_check" -std=c++11 -I third_party/testlib
echo "Running $1_gen..."
".tmp/$1_gen" > ".tmp/$1.in"
echo "Running $1..."
".tmp/$1" < ".tmp/$1.in" > ".tmp/$1.out"
echo "Running $1_bf..."
".tmp/$1_bf" < ".tmp/$1.in" > ".tmp/$1_bf.out"
echo "Running $1_check..."
".tmp/$1_check" ".tmp/$1.in" ".tmp/$1.out" ".tmp/$1_bf.out"
echo "The test $1 has passed."

rm -r .tmp
