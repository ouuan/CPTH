## BIT

BIT is binary indexed tree, or Fenwick tree. You can add a value to an element, and query for the prefix sums.

The range is started from 1, so the range is [1, size].

### Template

`BIT<T>`, where T is the type of the values.

### Functions

`BIT()`: Construct an empty BIT.

`BIT(size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero = T())`: Construct a BIT with the size of `size`, the function `_merge` is used for adding up two values, and the result of `_merge(_zero, x)` where `x` is an element of `T` is always `x`.

`void init(size_t _size, std::function<T(const T &, const T &)> _merge, const T &_zero = T())`: The same as the above constructor.

`void add(size_t p, const T &x)`: Add `x` to the element `p`.

`T query(size_t p) const`: Get the sum of [1, p].

`size_t size() const`: Get the size of the BIT.

`void clear()`: Clear the BIT in O(1).
