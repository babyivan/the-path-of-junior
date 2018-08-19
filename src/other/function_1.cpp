/*
 * std::function
 * ... полиморфная обертка над функцией ... некий аналог указателя на функцию
 */

#include <iostream>
#include <functional>

void foo() {
  std::cout << "void foo()" << std::endl;
}

int bar(const int &a, const int &b) {
  return a + b;
}

int main() {
  std::function<void()> f1;    // <сигнатура функции>
  f1 = foo;                     // присваиваем функцию
  f1();                         // void foo()

  std::function<int(int, int)> f2;    // <сигнатура функции>
  f2 = bar;                            // присваиваем
  std::cout << f2(4, 5);               // 9

  return 0;
}
