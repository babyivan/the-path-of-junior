#include <iostream>
/*
 *
 * Перегрузка функций
 *
 */

int sum(int a, int b) {
  return a + b;
}

float sum(float a, float b) {
  return a + b;
}

int main() {
  std::cout << sum(1, 2) << std::endl;
  std::cout << sum(1.1, 2.2) << std::endl;
  return 0;
}