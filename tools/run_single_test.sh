#!/bin/bash

if (($# != 1)); then
    echo 'tools//run_single_test.sh <testName>'
    exit 1
fi

set -e

mkdir -p .tmp

echo "Running the test $1..."
echo "Compiling $1.cpp..."
g++ "tests/$1/$1.cpp" -o ".tmp/$1" -Wall -Wshadow -Wextra -Werror -std=c++11
echo "Compiling $1_gen.cpp..."
g++ "tests/$1/$1_gen.cpp" -o ".tmp/$1_gen" -Wall -Wshadow -Wextra -Werror -std=c++11
echo "Compiling $1_bf.cpp..."
g++ "tests/$1/$1_bf.cpp" -o ".tmp/$1_bf" -Wall -Wshadow -Wextra -Werror -std=c++11
echo "Compiling $1_check.cpp..."
g++ "tests/$1/$1_check.cpp" -o ".tmp/$1_check" -std=c++11 -I third_party/testlib
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
