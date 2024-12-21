#include "hash-example.cpp"
#include "swap-example.cpp"
#include "pair-example.cpp"
#include "tuple-example.cpp"
#include "optional-example.cpp"
#include "variant-example.cpp"

int main() {
  hash();
  hashOverride();

  swapExample();

  pairExample();

  tupleExample();

  optionalExample();

  variantExample();

  return 0;
}