
#include <iostream>
#include <optional>
#include <string>

const auto optionalExample = []() {
  std::optional<std::string> possibleString;

  std::cout << possibleString.has_value() << std::endl;
  std::cout << possibleString.value_or("No Value") << std::endl;

  possibleString.emplace("New Populated String");

  std::cout << possibleString.has_value() << std::endl;
  std::cout << possibleString.value() << std::endl;

};