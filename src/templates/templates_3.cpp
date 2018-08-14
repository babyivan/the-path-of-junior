#include <iostream>
#include <typeinfo>
/*
 *
 * Наследование шаблонов класса
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

template<typename T>
class type_size {
 public:
  explicit type_size(T value) {
    this->value = value;
  }
  void data_size_type() {
    std::cout << "size: " << sizeof(T) << std::endl;
  }

 protected:
  T value;
};

// Сохраняем "шаблонность" наследуемого класса
template<class U>
class type_info : public type_size<U> {
 public:
  explicit type_info(U val)
      : type_size<U>(val) {}
  void show_type_name() {
    std::cout << "Type name: " << typeid(type_size<U>::value).name() << std::endl;
  }

};

int main() {
  type_info<int> ti1(1);
  ti1.data_size_type();     // size: 4
  ti1.show_type_name();     // Type name: i

  test_class tc;
  type_info<test_class> ti2(tc);
  ti2.data_size_type();     // size: 12
  ti2.show_type_name();     // Type name: 10test_class    (10test_class)??
  return 0;
}
