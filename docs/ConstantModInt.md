## ConstantModInt

It's similar to [ModInt](ModInt.md), but the modulo is a template parameter in `ConstantModInt`, so the compiler can make more optimization and result in 60%~70% faster. But in this way, the modulo number must be a compile-time constant.

### Declaration

`ConstantModInt<mod>`, where `mod` is the modulo number.

### Functions

Please read the [source file](../headers/ConstantModInt.h) and [the document of ModInt](ModInt.md) for more information.
