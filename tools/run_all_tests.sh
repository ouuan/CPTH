#!/bin/bash

set -e

for i in tests/*/; do
    x=${i#tests/}
    test=${x%/}
    tools/run_single_test.sh "$test"
done

echo "All tests passed."
