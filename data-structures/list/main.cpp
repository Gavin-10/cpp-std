
#include <iostream>
#include <list>

struct Point {
  int x, y;

  Point() = default;

  Point(int x, int y) : x(x), y(y) {};

  Point(const Point& point) : x(point.x), y(point.y) {
    std::cout << "Copy" << std::endl;
  };
};

std::ostream& operator << (std::ostream& out, const Point& point) {
  out << point.x << ", " << point.y << std::endl;
  return out;
}

int main() {
  std::list<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  //Element access

  std::cout << points.front() << std::endl;
  std::cout << points.back() << std::endl;

  //Capacity

  std::cout << points.empty() << std::endl;
  std:: cout << points.size() << std::endl;
  std::cout <<points.max_size() << std::endl;

  //Modifiers generally the same

  //Operations

  std::list<int> a = {1, 2, 3, 4, 5};
  std::list<int> b = {6, 7, 8, 9, 10};
  a.merge(b);

  std::list<int> c = {1, 2, 3, 4, 5};
  std::list<int> d = {6, 7, 8, 9, 10};

  auto it = d.begin();
  std::advance(it, 2);

  d.splice(it, c);
  d.reverse();

  //just unique() removed adjacent identical elements
  std::list<int> odds = {1, 3, 4, 5, 7, 9};
  odds.unique([](int x, int y) {
    return x == --y;
  });

  std::list<int> evens = {1, 2, 4, 6, 8, 10, 11};
  //removes elements equal to param
  evens.remove(11);
  //lambda
  evens.remove_if([](int x) { return x % 2 == 1; });

  std::list<int> someNums = {1, 5, 2, 4, 3, 9, 7, 8};
  someNums.sort();

  someNums.sort(std::greater<int>());

  return 0;
}