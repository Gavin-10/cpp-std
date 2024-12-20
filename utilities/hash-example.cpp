#include <string>
#include <iostream>

const auto hash = []() {
  std::string message = "This is a new message";
  std::size_t hash_message = std::hash<std::string>{}(message);

  std::cout << hash_message << std::endl;
};

//overloading default hash

struct Person {
  std::string firstName;
  std::string lastName;
  bool operator==(const Person&) const = default;
};

template<>
struct std::hash<Person> {
  std::size_t operator()(const Person& p) const noexcept {
    std::size_t h1 = std::hash<std::string>{}(p.firstName);
    std::size_t h2 = std::hash<std::string>{}(p.lastName);
    return h1 ^ (h2 << 1);
  }
};

const auto hashOverride = []() {
  Person p("Anna", "Freeman");
  std::cout << std::hash<Person>{}(p) << ", Custom injected hash" << std::endl; 
};