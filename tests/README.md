# Tests

A test is a problem that can be solved by using one or more headers of CPTH.

Each test has the following files:

- `testName.md`, describe the problem.
- `testName.cpp`, use CPTH to solve the problem.
- `testName_bf.cpp`, use brute force to solve the problem.
- `testName_gen.cpp`, generate a testcase for the problem.
- `testName_check.cpp`, use [testlib](https://github.com/MikeMirzayanov/testlib) to check if the answer is correct.

You can run `run_all_tests.sh` or `run_single_test.sh` to run the tests locally. (On Windows, you can use Git bash to run it.)
