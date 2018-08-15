/*
 * Специализация шаблонов класса
 * это шаблон заточенный под определенный тип данных ?
 * хак - таким образом можно запрещать использовать шаблон с нужным типом данных
 */

#include <iostream>
#include <typeinfo>

template<class T>
class printer {
 public:
  explicit printer() {}

  void print(const T &val) {
    std::cout << "value is: " << val << std::endl;
  }
};

template<>
class printer<std::string> {
 public:
  explicit printer() {}

  void print(const std::string &val) {
    std::cout << "[value is: " << val << "]" << std::endl;
  }
};

int main() {
  printer<int> p1;
  p1.print(123);     // value is: 123

  printer<std::string> p2;
  p2.print("123str123");     // [value is: 123str123]
  return 0;
}
