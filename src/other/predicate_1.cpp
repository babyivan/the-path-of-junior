#include <iostream>
/*
 *
 * Предикаты
 *
 */
class my_functor {
 public:
  void operator()(const int &a, const int &b) {
    std::cout << "my_functor -> " << (a + b) <<
              ", call count: " << count << std::endl;
    count++;
  }
 private:
  int count = 1;
};

int main() {
  my_functor f;

  f(1, 2);  // my_functor -> 3, call count: 1
  f(3, 4);  // my_functor -> 7, call count: 2
  f(5, 6);  // my_functor -> 11, call count: 3

  return 0;
}