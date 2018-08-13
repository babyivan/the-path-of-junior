#include <iostream>
/*
 *
 * Чисто виртуальный диструктор...
 * на деле тот-же абстрактный класс с нестандартным синтаксисом
 * std::cout в конструкторах чисто для наглядности
 */

class A {
 public:
  A() {
    std::cout << "A()  ";
  };
  virtual ~A() = 0;
};
// Иначе не скомпилируется !
// undefined reference to `virtual5::A::~A()'
A::~A() { std::cout << "~A()  "; }

class B : public A {
 public:
  B() {
    std::cout << "B()  ";
  };
  ~B() override {
    std::cout << "~B()  ";
  }
};

int main() {
//   A aa; // Не скомпилируется "A" - абстрактный класс
  A *a = new B; //A()  B()
  delete (a); //~B()  ~A()

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
}
