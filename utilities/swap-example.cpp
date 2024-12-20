
#include <iostream>
#include <algorithm>

class A {
  friend void swap(A& obj1, A& obj2) {
    std::cout << "Swapping" << std::endl;;
    std::swap(obj1.id, obj2.id);
  }

  friend std::ostream& operator << (std::ostream& out, const A& a) {
    out << "Object with id: " << a.id;
    return out;
  }

  public:
    int id{0};
};

const auto swapExample = []() {
  int a = 3, b = 5;
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;

  A obj1(12); 
  A obj2(34);
  std::cout << "obj1: " << obj1 << std::endl;
  std::cout << "obj2: " << obj2 << std::endl;

  swap(obj1, obj2);

  std::cout << "obj1: " << obj1 << std::endl;
  std::cout << "obj2: " << obj2 << std::endl;
};