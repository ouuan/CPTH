## ModInt

### Description

You are given an integer `x` which is initially zero and a prime number `m`. You are asked to perform `n` operations and print `x` modulo `m` after each operation. 

Here "a mod b = c" means 0 <= c <= b - 1 and there exists an integer p such that a = b * p + c

### Input

The first line contains two integers `n` and `m` (1 <= n <= 1000000, 2 <= m <= 1000000000, m is prime).

Each of the following `n` lines contains an operation, where 0 <= a <= 1000000000:

1. `1 a`: x <- x + a
2. `2 a`: x <- x - a
3. `5 a`: x <- a - x
4. `3 a`: x <- x * a
5. `4 a`: x <- k, where (a * k) mod m is x (1 <= a <= m - 1)

### Output

For each operation, print `x` modulo `m` after the operation.
