/*
 * throw, exception и несколько catch
 */

#include <iostream>
#include <fstream>

namespace a {
void print_number(int value) {
  if (value < 0)
    throw value;    // Exception "int" type !
  std::cout << value << std::endl;
}
}

namespace b {
void print_number(int value) {
  if (value < 0)
    throw "number < 0";    // Exception "char *" type !
  std::cout << value << std::endl;
}
}

namespace c {
void print_number(int value) {
  if (value < 0)
    throw std::runtime_error("std exception");    // Exception "exception" type !
  std::cout << value << std::endl;
}
}

namespace d {
void print_number(int value) {
  if (value < 0)
    throw std::runtime_error("std exception");    // Exception "exception" type !
  else if (value == 0)
    throw 0.1f;                                   // Exception "float" type !
  else if (value == 1)
    throw "Wow Exception";
  std::cout << value << std::endl;
}
}

int main() {
  // a::print_number(-1); // Terminate called after throwing an instance of 'int'
                          // This application has requested the Runtime to terminate it in an unusual way.
                          // Please contact the application's support team for more information.
  {
    using namespace a;

    try {
      print_number(-1);   // what: [-1]
    } catch (const int &ex) {
      std::cout << "what: [" << ex << "]" << std::endl;   // what: [-1]
    }
  }
  ////
  {
    using namespace b;

    try {
      print_number(-1);   // what: [number < 0]
    } catch (const char *ex) {
      std::cout << "what: [" << ex << "]" << std::endl;   // what: [number < 0]
    }
  }
  ////
  {
    using namespace c;

    try {
      print_number(-1);   // what: [std exception]
    } catch (const std::exception &ex) {
      std::cout << "what: [" << ex.what() << "]" << std::endl;   // what: [std exception]
    }
  }
  ////
  {
    using namespace d;

    try {
      //  print_number(0);    // what: [0.1]
      //  print_number(-1);   // what: [std exception]
      //  print_number(1);    // [...]
    } catch (const std::exception &ex) {
      std::cout << "what: [" << ex.what() << "]" << std::endl;   // what: [std exception]
    } catch (const float &ex) {
      std::cout << "what: [" << ex << "]" << std::endl;   // what: [0.1]
    } catch (...) {
      std::cout << "[...]" << std::endl;   // [...]
    }
  }
  return 0;
}