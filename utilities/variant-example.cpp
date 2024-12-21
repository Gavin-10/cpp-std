
#include <iostream>
#include <variant>

const auto variantExample = []() {
  std::variant<int, double> v, w;
  v = 10;

  w = std::get<int>(v);

  try {
    std::get<double>(w);
  } catch (const std::bad_variant_access& ex) {
    std::cout << ex.what() << std::endl;
  }

  v = 23.5;

  try {
    std::cout << std::get<double>(v) << std::endl;
  } catch (const std::bad_variant_access& ex) {
    std::cout << ex.what() << std::endl;
  }
};