/*
 * Queue, Priority queue
 * ... адаптер контейнара ...
 *
 * ---- Queue ----
 * в качестве контейнера - vector, list, deque, по умолчанию - deque.
 *
 * ---- Priority queue ----
 * только vector и deque в качестве контейнера, по умолчанию - vector.
 * сортируються при добавлении от большего к меньшему
 *
 * --- Операции ---
 * -> push()          - добавление элемента в контейнер.
 * -> pop()           - удаляет самый первый добавленый элемент.
 * -> emplace() C++11 - создает объект в момент выполения.
 * -> empty()         - проверка есть ли элементы в контейнере.
 * -> size()          - количество (размер) в контейнера.
 *
 * --- Queue ONLY
 * -> front()         - получить последний элемент очереди.
 * -> back()          - получить первый элемент очереди.
 */

#include <iostream>
#include <queue>

int main() {
  std::queue<int> queue1;

  queue1.push(3);      // queue1 = {3}
  queue1.push(12);     // queue1 = {3, 12}
  queue1.emplace(235); // queue1 = {3, 12, 235}
  queue1.push(44);     // queue1 = {3, 12, 235, 44}

  std::cout << queue1.front() << std::endl;  // 3
  std::cout << queue1.back() << std::endl;   // 44

  queue1.pop();       // queue1 = {12, 235, 44}

  /////////////////////////////////
  std::priority_queue<int> queue2;

  queue2.push(3);      // queue2 = {3}
  queue2.push(12);     // queue2 = {12, 3}
  queue2.emplace(235); // queue2 = {235, 12, 3}
  queue2.push(44);     // queue2 = {235, 44, 12, 3}

  std::cout << queue2.top() << std::endl;;  // 235

  queue2.pop();       // queue2 = {44, 3, 12}

  return 0;
}
