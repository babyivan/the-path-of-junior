/*
 * Stack
 * ... адаптер контейнара ...
 *
 * --- Операции ---
 * -> push()          - добавление элемента в контейнер.
 * -> emplace() C++11 - создает объект в момент выполения.
 * -> pop()           - удалить последний элемент из контейнера.
 * -> top()           - возращает последний элемент из контейнера.
 * -> empty()         - проверка есть ли элементы в контейнере.
 * -> size()          - количество (размер) в контейнера.
 */

#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::stack<int> stack;

  stack.push(53);
  stack.push(12);
  stack.emplace(235);
  stack.push(44);

  std::cout << stack.top();  // 4


  return 0;
}
