/*
 * Шаблонны функций
 * typename (из языка "С") и class(пришло в "С++") - одно и тоже.
 */

#include <iostream>

// T - это один тип данных
template<typename T>
T sum(const T &a, const T &b) {
  std::cout << "type size: " << sizeof(T) << "; typename: " << typeid(T).name() << std::endl;
  return a + b;
}

// T - это один тип данных, U - другой тип
template<typename T, typename U>
T sum(const T &a, const U &b) {
  return a + b;
}

int main() {
  std::cout << sum(1, 2) << std::endl;      // type size: 4; typename: i     // 3
  std::cout << sum(1.1, 2.2) << std::endl;  // type size: 8; typename: d    // 3.3
  std::cout << sum(1, 2.2L) << std::endl;   // 3 (первый параметр типа int, вызываем [template<typename T, typename U>] тип возвращаемого значения T (int))
                                            // результат сложения неявно будет преобразован в тип int.
  return 0;
}
