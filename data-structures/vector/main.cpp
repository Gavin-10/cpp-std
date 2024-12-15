
#include <iostream>
#include <string>
#include <vector>

struct Vertex {
  float x, y, z;

  Vertex() = default;

  Vertex(int x, int y, int z) : x(x), y(y), z(z) {};

  Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z) {
    std::cout << "Copied" << std::endl;
  }
};

std::ostream& operator << (std::ostream& out, const Vertex& vertex) {
  out << vertex.x << ", " << vertex.y << ", " << vertex.z;
  return out;
}

void basicVector() {
  //With array
  Vertex* vert = new Vertex[5];
  delete vert;

  //can use primatives
  std::vector<Vertex> verticies;
  verticies.push_back({1, 2, 3});
  verticies.push_back({4, 5, 6});
  verticies.push_back({0, 6, 2});

  for (Vertex& v : verticies) {
    std::cout << v << std::endl;
  }

  verticies.at(0) = {8, 9, 10};
  std::cout << verticies[0] << std::endl;

  std::cout << verticies.front() << std::endl;
  std::cout << verticies.back() << std::endl;

  //capacity
  //.empty, .size, .max_size, .reserve, .capacity, .shrink_to_fit
  //NOTE: pop_back doesnt return value poped #lame

  //doesnt take an int, needs an iterator :(
  verticies.erase(verticies.begin() + 1);
  verticies.insert(verticies.begin() + 1, {7, 2, 3});

  verticies.clear();
}

void optimizedArrays() {

  //reserve known size
  std::vector<Vertex> verticies;
  verticies.reserve(3);
  //switch push_back with emplace_back to avoid copying from main stack to vector stack
  //also use emplace instead of insert
  verticies.emplace_back(1, 2, 3);
  verticies.emplace_back(4, 5, 6);
  verticies.emplace_back(0, 6, 2);

  std::cout << "No Copies" << std::endl;
}

int main() {
  basicVector();
  std::cout << "----------------------------" << std::endl;
  optimizedArrays();

  return 0;
}