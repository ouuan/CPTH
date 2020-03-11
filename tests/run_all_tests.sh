#!/bin/bash

set -e

for i in *_gen.cpp; do
    test=${i%_gen.cpp}
    ./run_single_test.sh "$test"
done

echo "All tests passed."
