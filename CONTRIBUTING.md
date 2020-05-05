# Welcome!

We are excited that you are willing to contribute to CPTH! After reading the following, you'll know how to write your own header and get merged into CPTH.

## First time to GitHub?

**Working on your first Pull Request?** You can learn how from this *free* series [How to Contribute to an Open Source Project on GitHub](https://egghead.io/series/how-to-contribute-to-an-open-source-project-on-github).

[Learn Git Branching](https://pcottle.github.com/learnGitBranching/) also helps you become a Git expert, but be calm, even you are not familiar with Git, you can also contribute to CPTH.

## Open an issue

Please follow the issue templates when opening issues, that would be very helpful.

## Add a test

Contributing is easy — you can just write CP problems using CPTH, and upload them in the [tests](tests)!

## Add a header

A header consists of the following:

1. The header itself at `headers/headerName.h`.
2. A document which describes how to use the header, including the description for each function, at `docs/headerName.md`.
3. A short introduction of this header and links to the header, the document and one of its tests at [HEADER_LIST.md](HEADER_LIST.md).
4. At least one test, which consists of:
   - `tests/testName/testName.md`, describe the problem.
   - `tests/testName/testName.cpp`, use CPTH to solve the problem.
   - `tests/testName/testName_bf.cpp`, use brute force to solve the problem.
   - `tests/testName/testName_gen.cpp`, generate a testcase for the problem.
   - `tests/testName/testName_check.cpp`, use [testlib](https://github.com/MikeMirzayanov/testlib) to check if the answer is correct.

You can use [create_header.sh](tools/create_header.sh) to generate the above files.

After finishing all the above files, you can run [run_all_tests.sh](tools/run_all_tests.sh).

After "All tests passed.", you are done!

Open a pull request, wait for review, apply the suggestions, then your changes will be merged.

## Rules

It's better to follow these rules:

1. Use Clang Format 9 and [.clang-format](.clang-format) to format your codes.
2. Silent all warnings in your codes.
3. Follow [this blog](https://chris.beams.io/posts/git-commit/) and [commitizen](https://github.com/commitizen/cz-cli) when writing commit messages.
4. Obey the [Code of Conduct](CODE_OF_CONDUCT.md).
