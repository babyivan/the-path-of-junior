/*
 * Алгоритмы в STL
 * ... некий набор функций который решает типичные задачи
 * ... все функции обычно возвращаю итератор на элемент коллекции, если не нашли - итератор на конец коллекции.
 * приставка "_if" означает что можно использовать предикат
 * ----
 * sort()            - обычная сортировка.
 * find()            - поиск только по принципу равенства (==).
 * find_if()         - поиск элемента по предикату.
 * find_if_not()     - инвентированый результат работы find_if().
 * copy()            - простое копирование одного контейнера в другой.
 * copy_if()         - копирование элементов согласно условию предиката.
 * remove()          - перемещает в конец контейнера все найденые элементы по принципу равенства (==)
 *                     и возвращает итератор на первый перемещенный в конец найденный элемент.
 * remove_if()       - ^^^ но по предикату.
 */

#include <iostream>
#include <algorithm>
#include <vector>

// Просто печать в консоль коллекции
template<class T>
void _print(const T &t, bool new_line = false) {
  for (const auto &v : t)
    std::cout << v << " " << (new_line ? "\n" : "");
  std::cout << std::endl;
}
const int collection_1_SIZE = 10;
int collection_1[collection_1_SIZE] = {54, 312, 44, 65, 10, 23, 11, 5, 99, 77};

std::vector<float>
    collection_2 = {54.1f, 312.03f, 44.11f, 65.0002f, 10.124f, 23.1185f, 11.11f, 5.25f, 99.00055f, 77.53f};

void f_sort() {
  std::cout << std::endl << "void f_sort()" << std::endl;

  std::vector<int> v_1 = {25, 47, 19, 7, 43, 12};
  // По умолчанию сортирует по возрастанию
  std::sort(v_1.begin(), v_1.end());    // v_1 = {7, 12, 19, 25, 43, 47}
  _print(v_1);
  // Сортируем лямбдой по убыванию
  std::sort(v_1.begin(), v_1.end(),
            [](const int &a, const int &b) { return a > b; }
  );    // v_1 = {47, 43, 25, 19, 12, 7}
  _print(v_1);
}

void find___find_if___find_if_not() {
  std::cout << std::endl << "find___find_if___find_if_not()" << std::endl;

  // Найти число "11"
  auto r1 = std::find(collection_1, collection_1 + collection_1_SIZE, 11);

  // Найти четные числа
  auto r2 = std::find_if(collection_1, collection_1 + collection_1_SIZE,
                      [](const int &a){ return a % 2 == 0; });
};

void copy___copy_if(){
  std::cout << std::endl << "copy___copy_if()" << std::endl;

  std::vector<float> collection_result;

  std::copy(collection_2.begin(), collection_2.end(), std::back_inserter(collection_result));
  _print(collection_result);      // 54.1 312.03 44.11 65.0002 10.124 23.1185 11.11 5.25 99.0005 77.53

  collection_result.clear();      // Удаляем все
  // Копируем по условию "v > 10.11f"
  std::copy_if(collection_2.begin(), collection_2.end(), std::back_inserter(collection_result),
               [](const float &v){ return v > 51.11f;});
  _print(collection_result);      // 54.1 312.03 65.0002 99.0005 77.53
}
void remove___remove_if(){
//TODO: написать примеры
}

int main() {
  f_sort();
  find___find_if___find_if_not();
  copy___copy_if();
  remove___remove_if();
  return 0;
}
