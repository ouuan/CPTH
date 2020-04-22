#!/bin/bash

if (($# != 1)); then
    echo "tools/create_header.sh <headerName>"
    exit 1
fi

set -e

touch "headers/$1.h" "docs/$1.md" "tests/$1.md" "tests/$1.cpp" "tests/$1_bf.cpp" "tests/$1_gen.cpp" "tests/$1_check.cpp"

headerdefine=CPTH_${1^^}

echo "// Get more headers at https://github.com/ouuan/CPTH

#ifndef $headerdefine
#define $headerdefine



namespace CPTH
{

}  // namespace CPTH

#endif // $headerdefine" > "headers/$1.h"

echo "## $1

" > "docs/$1.md"

echo "#include \"$1.h\"

#include <iostream>
#include <cstdio>

int main()
{


    return 0;
}" > "tests/$1.cpp"

echo '#include <iostream>
#include <cstdio>

int main()
{


    return 0;
}' > "tests/$1_bf.cpp"

echo '#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) { return rnd() % (r - l + 1) + l; }

int main()
{


    return 0;
}' > "tests/$1_gen.cpp"

echo '#include "checkers/"' > "tests/$1_check.cpp"

echo "## $1

### Description



### Input



### Output

" > "tests/$1.md"

echo "
## $1



- [$1.h](headers/$1.h)
- [$1.md](docs/$1.md)
- [$1.cpp](tests/$1.cpp)" >> HEADER_LIST.md
