# Tests

A test is a problem that can be solved by using one or more headers of CPTH.

Each test has the following files:

- `category/testName.md`, describe the problem.
- `category/testName.cpp`, use CPTH to solve the problem.
- `category/testName_bf.cpp`, use brute force to solve the problem.
- `category/testName_gen.cpp`, generate a testcase for the problem.
- `category/testName_check.cpp`, use [testlib.h](../testlib/testlib.h) to check if the answer is correct.

You can run `run_tests.sh` to run the tests locally. (On Windows, you can use Git bash to run it.)
