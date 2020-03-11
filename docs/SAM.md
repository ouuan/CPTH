## SAM

SAM is the [suffix automaton](https://en.wikipedia.org/wiki/Suffix_automaton), you can learn it at [后缀自动机（SAM）学习笔记 - ouuan](https://ouuan.github.io/post/%E5%90%8E%E7%BC%80%E8%87%AA%E5%8A%A8%E6%9C%BAsam%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0/).

This template supports arbitary character type, can construct the SAM and the parent tree.

## Template

`SAM<>`: A SAM with `char` as the character type.

`SAM<charType>`: A SAM with `charType` as the character type.

`charType`: A type with `operator<` satisfying strict weak ordering.

## Node

```cpp
struct SAMNode
{
    int pa, len;
    std::map<charType, int> ch;
    SAMNode() : pa(-1), len(0) {}
    int &operator[](int x) { return ch[x]; }
};
```

`pa`: The parent of the node.

`len`: The maximum length of the node.

`ch`: The child of the node.

The root node is the node `0`, its parent is `-1`.

## Functions

`explicit SAM()`: Construct an empty SAM.

`explicit SAM(const charType &x)`: Contruct a SAM with a single character.

`template <typename T> explicit SAM(const T &str)`: The type `T` should be a container of `charType` (for example, `string` is valid if `charType` is `char`, `vector<int>` is valid if `charType` is `int`). Construct a SAM with the container as the string.

`int append(const charType &x)`: Add a character at the back of the SAM, return the number of the node corresponding to the current string.

`template <typename T> void append(const T &str)`: The type `T` should be a container of `charType`. Add a string at the back of the SAM.

`void clear()`: Clear the SAM (make it empty).

`void buildTree()`: Build the parent tree.

`unsigned int size() const`: Get the number of nodes in the SAM, including the root node.

`const SAMNode &operator[](unsigned int x) const`: Get the node x of the SAM.

`const std::vector<int> &children(unsigned int x) const`: Get the children of the node x on the parent tree.
