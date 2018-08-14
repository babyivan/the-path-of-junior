#include <iostream>
/*
 *
 * Перегрузка функций
 * ...
 * Нельзя перегружать:
 * - Перегружать по типу возвращаемого значения
 *
 * Льзя перегружать:
 * - Число аргументов
 * - Тип аргументов
 * - Наличие или отсутствие многоточия
 */

int sum(int a, int b) {
  std::cout << "int sum(int a, int b)" << std::endl;
  return a + b;
}
// Ошибка - так нельзя перегружать нельзя (неоднозначность вызова)
int sum(int &a, int &b) {
  std::cout << "int sum(int &a, int &b)" << std::endl;
  return a + b;
}
// Ошибка - нельзя перегружать по типу возвращаемого значения
//double sum(int a, int b) {
//std::cout << "double sum(int a, int b)" << std::endl;
//  return double(a + b);
//}

float sum(float a, float b) {
  std::cout << "float sum(float a, float b)" << std::endl;
  return a + b;
}

int main() {
  std::cout << sum(1, 2) << std::endl;        // int sum(int a, int b)         // 3
  std::cout << sum(1.1f, 2.2f) << std::endl;  // float sum(float a, float b)   // 3.3
  return 0;
}