
#include <iostream>
#include <deque>

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
  std::deque<Point> points;

  //Capacity

  std::cout << points.empty() << std::endl;

  std::cout << points.size() << std::endl;

  std::cout << points.max_size() << std::endl;

  //also shrink_to_fit

  //Modifiers

  points.push_back({23, 45});
  points.push_back({76, 35});
  points.push_back({92, 389});

  points.insert(points.begin() + 1, {1, 2});
  //emplace used to avoid copy

  points.push_front({1, 2});

  //element access
  std::cout << points[0] << std::endl;
  std::cout << points.at(3) << std::endl;
  std::cout << points.front() << std::endl;
  std::cout << points.back() << std::endl;

  points.pop_back();
  points.pop_front();
  points.erase(points.end());
  points.clear();

  return 0;
}