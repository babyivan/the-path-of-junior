/*
 * Множественное наследование - вызов одинаковых методов из классов наследников
 */

#include <iostream>

class printer {
 public:
  explicit printer() {
    std::cout << "printer()  ";
  }
  ~printer() {
    std::cout << "~printer()  ";
  }

  void use() {
    std::cout << "printing...  ";
  }
};

class scanner {
 public:
  explicit scanner() {
    std::cout << "scanner()  ";
  }
  ~scanner() {
    std::cout << "~scanner()  ";
  }

  void use() {
    std::cout << "scanning...  ";
  }
};

// all-in-one устройство (МФУ как пример)
class AIO : public printer, public scanner {
 public:
  explicit AIO() {
    std::cout << "AIO()  ";
  }
  ~AIO() {
    std::cout << "~AIO()  ";
  }
};

int main() {
  AIO a;      // printer()  scanner()  AIO()
  // a.use();  //error: request for member 'use' is ambiguous

  // Варианты использования:

  // В стиле "С" но тут срабатывает деструктор?? (MinGW w64 5.0)
  ((printer) a).use();   //printing...  ~printer()
  ((scanner) a).use();   //printing...  ~scanner()
  std::cout << std::endl;

  // можно через пространство имен (студия ругается но код компилирует и выполняет)
  a.printer::use();   //printing...
  a.scanner::use();   //scanning...

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  // ~AIO()  ~scanner()  ~printer()
}
