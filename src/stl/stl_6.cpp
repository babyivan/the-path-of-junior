/*
 * Deque
 * ... реализация двусторонней очереди ... в STL ... некий гибрид вектора и двусвязного списка
 *     каждый элемент является небольшим динамическим массивом которые связаны между собой на основе двусвязного списка
 *     получаеться дек - это двусвязный список маленьких векторов.
 * [] - перегружен.
 * Огромная скорость доступа в начало/конец коллекции (на вставку/удаление/получение)
 *
 * --- Операции ---
 * -> at()            - получить элемент по индексу (== arr[i]). Если выходим за границы - получаем exception.
 *                      работает медленнее чем [] поскольку проверяет выход за границу.
 * -> push_back()     - добавление элемента в конец контейнера.
 * -> push_front()    - добавление элемента в начало контейнера.
 * -> front()         - получить первый элемент.
 * -> back()          - получить последний элемент.
 * -> empty()         - проверка есть ли элементы в контейнере.
 * -> clear()         - очистить контейнер от всех элементов.
 * -> pop_back()      - удалить последний элемент из контейнера.
 * -> pop_front()     - удалить первый элемент из контейнера.
 * -> size()          - количество (размер) в контейнера.
 * -> assign()        - Заполняет лист указаными элементами.
 * -> shrink_to_fit() - удалить незанятое место из вектора (capacity = size).
 *           C++11 ^^
 * -------------------------------------------------------------------------------
 * -> insert()        - вставка элемента в лист по итератору. !!! Итератор после вставки обнуляется !!!
 * -> erase()         - удаление элемента из листа по итератору.
 * ---
 * -> begin()         - возвращает итератор на первый элемент коллекции.
 * -> cbegin()        - возвращает const итератор на первый элемент коллекции.
 * -> rbegin()  C++11 - возвращает reverse итератор на первый элемент коллекции.
 * -> cregin()  C++11 - возвращает const reverse итератор на первый элемент коллекции.
 * ---
 * -> end()           - возвращает итератор на след. элемент который идет после последнего элемента в коллекции.
 * -> cend()    C++11 - возвращает const итератор на след. элемент который идет после последнего элемента в коллекции.
 * -> rend()          - возвращает reverse итератор на след. элемент который идет после последнего элемента в коллекции.
 * -> crend()   C++11 - возвращает const reverse итератор на след. элемент который идет после последнего элемента в коллекции.
 */

#include <iostream>
#include <deque>

int main() {
  std::deque<int> deque;
  std::deque<int> deque_1 = {5, 23, 86, 32, 86};    // можно и так

  deque.push_back(2);    // deque = {2}
  deque.push_front(33);  // deque = {33, 2}
  deque.push_back(48);   // deque = {33, 2, 48}
  deque.push_front(14);  // deque = {14, 33, 2, 48}

  deque_1.assign(3, 777);  // deque_1 = {777, 777, 777}

  auto it = deque.begin();

  deque.insert(it, 234); // deque = {234, 48, 2, 33, 14}

  std::advance(it, 2);   // сдвигаемся на 2 элемента

  deque.insert(it, 50);  // deque = {234, 48, 2, 50, 33, 14}

  return 0;
}
