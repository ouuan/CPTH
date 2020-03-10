#!/bin/bash

if (($# != 2)); then
    echo './run_single_test.sh <category> <testName>'
    exit 1
fi

set -e

mkdir -p tmp

category=$1
test=$2
echo "Running the test $test..."
echo "Compiling $test.cpp..."
g++ "$category/$test.cpp" -o "tmp/$test" -Wall -Wshadow -Wextra -Werror -std=c++11 -I "../headers/$category"
echo "Compiling ${test}_gen.cpp..."
g++ "$category/${test}_gen.cpp" -o "tmp/${test}_gen" -std=c++11 -I Tree-Generator
echo "Compiling ${test}_bf.cpp..."
g++ "$category/${test}_bf.cpp" -o "tmp/${test}_bf" -std=c++11
echo "Compiling ${test}_check.cpp..."
g++ "$category/${test}_check.cpp" -o "tmp/${test}_check" -std=c++11 -I testlib
echo "Running ${test}_gen..."
"tmp/${test}_gen" > "tmp/$test.in"
echo "Running ${test}..."
"tmp/$test" < "tmp/$test.in" > "tmp/$test.out"
echo "Running ${test}_bf..."
"tmp/${test}_bf" < "tmp/$test.in" > "tmp/${test}_bf.out"
echo "Running ${test}_check..."
"tmp/${test}_check" "tmp/$test.in" "tmp/$test.out" "tmp/${test}_bf.out"
echo "The test $test has passed."

rm -r tmp
