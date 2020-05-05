## ModInt

Integer modulo a number.

### Public Member Functions

`ModInt(int modulo = 1, long long value = 0)`: Construct a ModInt with `modulo` as the modulo and `value` as the value. `modulo` should be in the range `[1, INT_MAX / 2]`.

`int toInt() const`: Get the value of the ModInt.

`int modulo() const`: Get the modulo of the ModInt.

`void setValue(long long x)`: Set the value of the ModInt.

`ModInt operator-()`: Get the opposite number of the ModInt, i.e. -x.

`ModInt operator~()`: Get the multiplication inverse of the ModInt, i.e. 1/x. The ModInt should be coprime to the modulo.

`ModInt pow(unsigned long long y)`: Get the ModInt to the power of `y`.

See the "Friend Functions" for details of the following member functions:

```cpp
ModInt &operator+=(ModInt y);
ModInt &operator+=(long long y);
ModInt &operator-=(ModInt y);
ModInt &operator-=(long long y);
ModInt &operator*=(ModInt y);
ModInt &operator*=(long long y);
ModInt &operator/=(ModInt y);
ModInt &operator/=(long long y);
```

### Friend Functions

#### Add

```cpp
ModInt operator+(ModInt x, ModInt y);
ModInt operator+(ModInt x, long long y);
ModInt operator+(long long x, ModInt y);
```

Get `x` + `y`.

In `ModInt operator+(ModInt x, ModInt y)`, `x` and `y` should have the same modulo.

#### Subtract

```cpp
ModInt operator-(ModInt x, ModInt y);
ModInt operator-(ModInt x, long long y);
ModInt operator-(long long x, ModInt y);
```

Get `x` - `y`.

In `ModInt operator-(ModInt x, ModInt y)`, `x` and `y` should have the same modulo.

#### Multiply

```cpp
ModInt operator*(ModInt x, ModInt y);
ModInt operator*(ModInt x, long long y);
ModInt operator*(long long x, ModInt y);
```

Get `x` * `y`.

In `ModInt operator*(ModInt x, ModInt y)`, `x` and `y` should have the same modulo.

#### Divide

```cpp
ModInt operator/(ModInt x, ModInt y);
ModInt operator/(ModInt x, long long y);
ModInt operator/(long long x, ModInt y);
```

Get a number `k` such that `k` * `y` ≡ `x` (mod modulo).

`y` should be coprime to the modulo.

In `ModInt operator/(ModInt x, ModInt y)`, `x` and `y` should have the same modulo.

#### Compare

`ModInt operator==(ModInt x, ModInt y)`: Return true iff x and y have the same value and the same modulo.

`ModInt operator<(ModInt x, ModInt y)`: Return true iff x has a smaller value than y or x and y have the same value and x has a smaller modulo than y.

#### Power

`ModInt pow(ModInt x, unsigned long long y)`: Get `x` to the power of `y`.
