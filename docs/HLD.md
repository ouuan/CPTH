## HLD

Heavy-light decomposition.

The nodes are numbered from `1` to `n`.

### Public functions

`HLD(std::size_t size = 0)`: Construct an HLD with `size` nodes.

`void reset(std::size_t size)`: Reset the HLD to a new HLD with `size` nodes.

`void addEdge(std::size_t u, std::size_t v)`: Add an bidirectional edge between `u` and `v`.

`void build(std::size_t root = 1)`: Build the HLD with node `root` as the root. You should call this after adding all edges, and before doing other operations.

`std::size_t lca(std::size_t u, std::size_t v) const`: Find the LCA between node `u` and node `v`. You have to build before calling this.

`std::size_t id(std::size_t u) const`: Get the place of node `u` in the DFS order.

`std::size_t atId(std::size_t x) const`: Get the node at the place `x` in the DFS order.

`std::size_t top(std::size_t u) const`: Get the top node of the heavy path of `u`.

`std::size_t bottom(std::size_t u) const`: Get the bottom node of the heavy path of `u`.

`std::size_t parent(std::size_t u) const`: Get the parent of the node `u`.

`std::vector<std::size_t> children(std::size_t u) const`: Get the children (adjacent nodes except the parent, if it's not the root) of node `u`.

`std::pair<std::size_t, std::size_t> subtree(std::size_t u) const`: Get the interval which represents for the subtree rooted on node `u` in the DFS order. i.e. suppose the return value is `{l, r}`, then a node is in the subtree rooted on `u` if and only if it's in the interval from the `l`-th node in the DFS order to the `r`-th node in the DFS order.

`std::vector<std::pair<std::size_t, std::size_t>> path(std::size_t u, std::size_t v) const`: Get the intervals which represents for the path between `u` and `v` in the DFS order.
