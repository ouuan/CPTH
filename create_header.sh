#!/bin/bash

if (($# != 2)); then
    echo "create_header.sh <category> <headerName>"
    exit 1
fi

set -e

mkdir -p headers/$1 docs/$1 tests/$1

touch headers/$1/$2.h docs/$1/$2.md tests/$1/$2.md tests/$1/$2.cpp tests/$1/$2_bf.cpp tests/$1/$2_gen.cpp tests/$1/$2_check.cpp

headerdefine=CPTH_${2^^}

echo "#ifndef $headerdefine
#define $headerdefine



#endif // $headerdefine" > headers/$1/$2.h

echo "## $2

" > docs/$1/$2.md

echo "#include \"$1/$2.h\"

#include <iostream>
#include <cstdio>

int main()
{


    return 0;
}" > tests/$1/$2.cpp

echo '#include <iostream>
#include <cstdio>

int main()
{
    

    return 0;
}' > tests/$1/$2_bf.cpp

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
}' > tests/$1/$2_gen.cpp

echo '#include "testlib.h"

int main()
{
    

    return 0;
}' > tests/$1/$2_check.cpp

echo "## $2

### Description



### Input



### Output

" > tests/$1/$2.md
