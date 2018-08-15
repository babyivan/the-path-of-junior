/*
 * Множественное наследование - простой пример
 * При множественном наследовании порядок (class AIO : public "printer", public "scanner")
 * классов наследников играеть роль в инициализации классов. Сначала инициализируется "printer", потом "scanner"
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

  void print() {
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

  void scan() {
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
  a.print();  // printing...
  a.scan();   // scanning...

  std::cout << std::endl;

  AIO *ptrAio = new AIO();    // printer()  scanner()  AIO()
  ptrAio->scan();             // scanning...
  ptrAio->print();            // printing...
  delete (ptrAio);            // ~AIO()  ~scanner()  ~printer()

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  // ~AIO()  ~scanner()  ~printer()
}
