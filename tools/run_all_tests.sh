#!/bin/bash

set -e

for i in tests/*_gen.cpp; do
    x=${i%_gen.cpp}
    test=${x#tests/}
    tools/run_single_test.sh "$test"
done

echo "All tests passed."
