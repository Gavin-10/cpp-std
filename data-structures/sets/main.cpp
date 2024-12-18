
#include <iostream>
#include <set>
#include <string>

int main() {
  std::set<std::string> uniqueNames;

  uniqueNames.insert("Anna");
  uniqueNames.insert("Ryan");
  uniqueNames.insert("Josilyn");
  uniqueNames.insert("Sophia");

  //lookup
  std::cout << *uniqueNames.find("Ryan") << std::endl;
  std::cout << uniqueNames.contains("Gavin") << std::endl;
  

  return 0;
}