
#include <iostream>
#include <string>
#include <tuple>

const auto tupleExample = []() {
  std::tuple<std::string, int> person;
  std::get<0>(person) = "My Name";
  std::get<1>(person) = 100;

  std::tuple<std::string, int> contactInfo = std::make_tuple("email@address.com", 2222222);

  auto personInfo = std::tuple_cat(person, contactInfo);

  std::cout << std::get<0>(personInfo) << " "
            << std::get<1>(personInfo) << " "
            << std::get<2>(personInfo) << " "
            << std::get<3>(personInfo) << " "
            << std::endl;
};