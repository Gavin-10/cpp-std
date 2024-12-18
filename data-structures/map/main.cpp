
#include <iostream>
#include <map>
#include <string>
#include <string_view>

int main() {
  std::map<int, std::string> students = {{1, "John"}, {2, "Fred"}, {3, "Susan"}};

  //not so good
  students.emplace(std::make_pair(1, std::string("Gavin")));

  //good
  students.try_emplace(1, std::string("Gavin"));
  students.try_emplace(4, std::string("Gavin"));

  //lookups
  std::cout << students.count(1) << std::endl;
  std::cout << students.find(4)->first << std::endl;
  std::cout << students.contains(2) << std::endl;
  

  return 0;
}