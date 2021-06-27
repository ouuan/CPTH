## UNRELEASED

### Added

- `const std::vector<size_t> &HLD::adjacent(size_t u) const`

### Changed

- `HLD::HLD(size_t size = 0)` => `explicit HLD::HLD(size_t size = 0)`
- `size_t &SAMNode::operator[](size_t x)` => `size_t &SAMNode::operator[](const charType &x)`

## 0.7.0

### Added

- `size_t HLD::size(size_t u) const`
- `size_t HLD::depth(size_t u) const`
- `size_t HLD::heavyChild(size_t u) const`

### Changed

- `void HLD::reset(size_t size)` => `void HLD::init(size_t size)`

### Fixed

- Now when `HLD::build(size_t root)` is called, it will be rebuilt if the root is changed.

## 0.6.0

### Added

- SparseTable

### Changed

- Use `size_t` instead of `std::size_t`.

## 0.5.0

### Added

- HLD
- Default constructor of ModInt

## 0.4.1

### Fixed

- Fixed `ModInt::operator~` and `ConstantModInt<mod>::operator~` when the modulo number is not prime.

## 0.4.0

### Added

- `operator==` and `operator<` for ModInt and ConstantModInt.

## 0.3.0

### Added

- ModInt and ConstantModInt

### Changed

- Split the declaration and the implementation.

## 0.2.0

### Added

- Minified version

## 0.1.0

### Added

- SegmentTree
- SAM
- BIT
- MonotonousQueue
