#include <iostream>
#include <fstream>
/*
 *
 * Свой простой класс exceptions
 *
 */

class my_exception : public std::runtime_error {
 public:
  my_exception(const char *ex, int data_state)
      : runtime_error(ex) {
    this->data_state = data_state;
  }

  const int &get_data_state() const { return data_state; }
 private:
  int data_state;
};

void print_number(int value) {
  if (value < 0)
    throw my_exception("my_exception@@!", value);        // Exception "my_exception" type !
  else if (value == 0)
    throw 0.1f;                                          // Exception "float" type !
  else if (value == 1)
    throw "Wow Exception";                               // Exception "const char *" type !
  std::cout << value << std::endl;
}

int main() {

  try {
    print_number(-1);    // what 2: [my_exception@@!]
                         // data_state: [-1]
  } catch (const my_exception &ex) {
    std::cout << "what 2: [" << ex.what() << "]" << std::endl                  // what 2: [my_exception@@!]
              << "data_state: [" << ex.get_data_state() << "]" << std::endl;   // data_state: [-1]
  } catch (const std::exception &ex) {
    std::cout << "what 1: [" << ex.what() << "]" << std::endl;   // Суда не дойдет. Но если поменять местами с [catch (const my_exception &ex)]
                                                                 // то выполниться именно [catch (const std::exception &ex)] поскольку
                                                                 // мы наследуем наш класс exception от std::exception
  }

  return 0;
}