## SegmentTree

### The problem

First, let's define a problem which can be solved by a segment tree (the version in this template) as following:

There is a sequence of **value**s a[1..n], and the **value**s are **merge**-able, which means you can **merge** two **value**s into one. If we merge x and y, we will get x + y, and the **value** of a subsequence a[l..r] is a[l] + a[l + 1] + … + a[r]. We can also perform **modification**s to a **value**.

(If you are familar with abstract algebra, you'll find that the **value**s form a [monoid](https://en.wikipedia.org/wiki/Monoid).)

The problem is: give you a sequence, you have to perform **modification** to some subsegment, or report the **value** of some subsegment.

For example: given you a sequence of integers, you have to either add x to a all integers of a subsegment or report the sum of a subsegment.

In this example, a **value** is an integer, to **merge** is to add two integers together, to perform a **modification** is to add an integer to an element in the sequence.

### The segment tree

Second, you have to know what a segment tree is, and the [lazy propagation tech](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/). You can find many resources about it on the Internet.

Then, we can find that, in most segment tree problems, the only difference is the type of **value** and **modification**, how to **merge**, and how to perform **modification**.

In this template, you only have to implement these key parts of a segment tree, and don't have to code the duplicate part of nearly every segment tree.

### Details

To construct a segment tree, you have to choose a type for the **value**, a type for the **modification** (which is `mod` in the codes), implement the `merge` function and the `update` function.

The declaration: `SegmentTree<valueType, modType, elementModificationOnly = false>`.

If `elementModificationOnly` is true, this segment tree can't do range modification, but it will have better performance.

#### Value

- supports the `=` operator
- has default constructor
- have a special element **valueZero**, where `merge(valueZero, x) == x` and `merge(x, valueZero) == x` for any possible **value** x. It can also be called "identity element". For example, it is 0 if merging is to add together, it is -INF (a sufficiently negative number) if merging is to calculate the max.

#### Modification

- supports the `=` operator
- has default constructor
- have a special element **modZero**. If you perform **modZero** to any **value**, the **value** keep unchanged. For example, it is 0 if modification is to add, it is INF (a sufficiently large number) if modification is to choose the smaller one between the old **value** and the **modification**.

#### node

```cpp
template <typename valueType, typename modType>
struct SegmentTreeNode
{
   public:
    size_t id;
    long long left, right;
    valueType val;
    modType mod;
};
```

- the `id` of the root is 1, the `id` of the left child of x is 2x, the `id` of the right child of x is 2x+1
- the `left` and `right` represent for the subsegment [left, right) of the node

#### merge

`valueType merge(const valueType &x, const valueType &y)`

The return value is the result of merging the two parameters.

#### update

`void update((SegmentTreeNode<valueType, modType> &node, const modType &mod))`

This function performs the modification `mod` to the `node`. If lazy propagation is needed, you also need to update `node.mod`.

#### public functions

`explicit SegmentTree()`: Construct an empty segment tree.

---

```cpp
explicit SegmentTree(
    const std::vector<valueType> &_initValue,
    std::function<valueType(const valueType &, const valueType &)> _merge,
    std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
    long long _startPoint = 1, const valueType &_valueZero = valueType(),
    const modType &_modZero = modType())
```

Construct a segment tree that:
- represents for the segment [`_startPoint`, `_startPoint` + `_initValue.size()`)
- initially a[i] = `initValue[i - _startPoint]`
- The merge function is `_merge`.
- The update function is `_update`.
- the identity element of values is `_valueZero`
- the no-effect element of mods is `_modZero`

Note: the `_startPoint` should be in the range `[LLONG_MIN / 2, LLONG_MAX / 2 - _initValue.size()]`.

You can use either a function pointer or a `std::function` (for example, a lambda) for `_merge` and `_update`.

You can also call `init(...)` with the same parameters to initialize a segment tree.

---

`void modify(long long l, long long r, const modType& mod)`: Perform the modification mod to the subsegment [l, r).

---

`void modify(void modify(long long p, const modType& mod)`: Perform the modification mod to the single element `a[p]`.

---

`valueType query(long long l, long long r)`: Return the value of the sum (merge result) of subsegment [l, r).

---

`valueType query(long long p)`: Return the value of the single element `a[p]`.
