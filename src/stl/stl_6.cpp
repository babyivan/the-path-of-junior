/*
 * Deque
 * ... реализация ... в STL
 * очень быстро происходит добавление/удаление элементов в коллекцию (по сравнению с vector)
 * [] - не перегружен, только итераторы.
 * не реализован произвольный доступ (лист же...)
 * не поддерживается арифметика указателей у итератора (std::advance никто не отменял)
 *
 * --- Операции ---
 * -> push_back()     - добавление элемента в конец контейнера.
 * -> push_front()    - добавление элемента в начало контейнера.
 * -> front()         - получить первый элемент.
 * -> back()          - получить последний элемент.
 * -> empty()         - проверка есть ли элементы в контейнере.
 * -> clear()         - очистить контейнер от всех элементов.
 * -> pop_back()      - удалить последний элемент из контейнера.
 * -> pop_front()     - удалить первый элемент из контейнера.
 * -> remove()        - удаление элемента из листа !!! по значению !!!. Если элемента с таким значением не существует - ничего не просходит.
 * -> size()          - количество (размер) в контейнера.
 * -> reverse()       - изменяет порядок элементов в контейнере списка - наоборот.
 * -> merge()         - ...
 * -> sort()          - ...
 * -> unique()        - Удаляем дубликаты !!! не все, только те, которые идут последовательно !!!
 * -> assign()        - Заполняет лист указаными элементами.
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
#include <list>

int main() {
  std::list<int> list;
  std::list<int> list_1 = {5, 23, 86, 32, 86};    // можно и так

  list.push_back(2);    // list = {2}
  list.push_front(33);  // list = {33, 2}
  list.push_back(48);   // list = {33, 2, 48}
  list.push_front(14);  // list = {14, 33, 2, 48}

  list_1.assign(3, 777);  // list_1 = {777, 777, 777}

  list.reverse();   // list = {48, 2, 33, 14}

  auto it = list.begin();

  list.insert(it, 234); // list = {234, 48, 2, 33, 14}

  std::advance(it, 2);  // сдвигаемся на 2 элемента

  list.insert(it, 50);  // list = {234, 48, 2, 50, 33, 14}

  return 0;
}
