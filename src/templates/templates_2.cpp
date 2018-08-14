#include <iostream>
/*
 *
 * Шаблонны класов
 * template - перед классом дает знать что класс будет обобщенным
 * T - название обобщенного типа данных (может быть несколько типов)
 * Тип данных становиться известным в момент создание этого класса
 *
 */

class test_class {
 public:
  test_class() {
    a = b = c = 0;
  }
 public:
  int a;
  int b;
  int c;
};
namespace t1 {
template<typename T>
class my_class {
 public:
  explicit my_class(T value) {
    this->value = value;
  }
  void data_size_type() {
    std::cout << "size: " << sizeof(T) << std::endl;
  }
 private:
  T value;
};
}
// Не перегжуються template по количеству параметров
namespace t2 {
template<typename T, typename U>
class my_class {
 public:
  explicit my_class(T value1, U value2) {
    this->value1 = value1;
    this->value2 = value2;
  }
  void data_size_type() {
    std::cout << "size1: " << sizeof(T) << std::endl;
    std::cout << "size2: " << sizeof(U) << std::endl;
  }
 private:
  T value1;
  U value2;
};
}

int main() {
  ::t1::my_class<int> mc1(777);
  mc1.data_size_type();    //size: 4

  test_class tc;
  ::t1::my_class<test_class> mc2(tc);
  mc2.data_size_type();    //size: 12

  ::t2::my_class<float, double> mc3(1.1f, 2.2);
  mc3.data_size_type();     // size1: 4    // size2: 8

  return 0;
}
