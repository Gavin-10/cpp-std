
#include <string>
#include <iostream>
#include <utility>

const auto pairExample = []() {
  std::pair<int, std::string> a;
  a.first = 42;
  a.second = "The Meaning Of Life";

  //additionall way to make
  std::pair<int, std::string> other = std::make_pair(19, "Num before 20");

  std::cout << a.second << ": " << a.first << std::endl;
};