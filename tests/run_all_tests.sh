#!/bin/bash

set -e

for i in */*_gen.cpp; do
    category=${i%/*}
    genfile=${i#$category/}
    test=${genfile%_gen.cpp}
    ./run_single_test.sh "$category" "$test"
done

echo "All tests passed."
