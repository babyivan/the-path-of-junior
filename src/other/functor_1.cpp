/*
 * Функторы
 * в принципе это как функция ... но функция способна хранить
 * промежуточные состояние данных и обладает всеми возможностями класса
 */

#include <iostream>

class my_functor {
 public:
  void operator()(const int &a, const int &b) {
    std::cout << "my_functor -> " << (a + b) <<
              ", call count: " << call_count << std::endl;
    call_count++;
  }
 private:
  int call_count = 1;
};

int main() {
  my_functor f;

  f(1, 2);  // my_functor -> 3, call count: 1
  f(3, 4);  // my_functor -> 7, call count: 2
  f(5, 6);  // my_functor -> 11, call count: 3

  return 0;
}
