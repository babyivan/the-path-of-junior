/*
 * typedef
 * чисто для удобства ... возможность присвоить какому-то типу данных alias
 */

#include <iostream>
#include <vector>

typedef std::vector<std::string> str_vec;

int main() {

  std::vector<std::string> v1;
  str_vec v2;

  // v1 === v2 // просто разное объявление

  return 0;
}
