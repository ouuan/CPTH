## HLD

Heavy-light decomposition.

The nodes are numbered from `1` to `n`.

### Public functions

`HLD(size_t size = 0)`: Construct an HLD with `size` nodes.

`void init(size_t size)`: Reset the HLD to a new HLD with `size` nodes.

`void addEdge(size_t u, size_t v)`: Add an bidirectional edge between `u` and `v`.

`void build(size_t root = 1)`: Build the HLD with node `root` as the root. You should call this after adding all edges, and before doing other operations.

`size_t lca(size_t u, size_t v) const`: Find the LCA between node `u` and node `v`. You have to build before calling this.

`size_t id(size_t u) const`: Get the place of node `u` in the DFS order.

`size_t atId(size_t x) const`: Get the node at the place `x` in the DFS order.

`size_t top(size_t u) const`: Get the top node of the heavy path of `u`.

`size_t size(size_t u) const`: Get the size of the subtree of `u`.

`size_t depth(size_t u) const`: Get the depth of `u`. The depth of the root is `0`.

`size_t bottom(size_t u) const`: Get the bottom node of the heavy path of `u`.

`size_t parent(size_t u) const`: Get the parent of the node `u`.

`size_t heavyChild(size_t u) const`: Get the heavy child of node `u`. If `u` is a leaf, it returns `0`.

`std::vector<size_t> children(size_t u) const`: Get the children (adjacent nodes except the parent, if it's not the root) of node `u`.

`std::pair<size_t, size_t> subtree(size_t u) const`: Get the interval which represents for the subtree rooted on node `u` in the DFS order. i.e. suppose the return value is `{l, r}`, then a node is in the subtree rooted on `u` if and only if it's in the interval from the `l`-th node in the DFS order to the `r`-th node in the DFS order.

`std::vector<std::pair<size_t, size_t>> path(size_t u, size_t v) const`: Get the intervals which represents for the path between `u` and `v` in the DFS order.
