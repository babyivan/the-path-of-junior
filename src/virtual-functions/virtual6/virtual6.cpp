#include <iostream>
/*
 *
 * Вызов виртуальных методов базового класса в классах наследниках
 *
 */
namespace virtual6 {
class message {
 public:
  explicit message(std::string msg) {
    this->msg = msg;
  }
  virtual std::string get_msg() {
    return msg;
  }
 private:
  std::string msg;
};
class custom_message : public message {
 public:
  explicit custom_message(std::string msg) : message(msg) {}
  // Перегрузка базового класа
  std::string get_msg() override {
    return "(" + ::virtual6::message::get_msg() + ")";  //::virtual6 - наш namespace, ::message:: - базовый класс
  }
};

class printer {
 public:
  void print(message *msg) {
    std::cout << msg->get_msg() << std::endl;
  }
};
}

using namespace virtual6;
int main() {
  message m("Hello");
  custom_message cm("Hello");

  printer p;
  p.print(&m);   // Hello
  p.print(&cm);  // (Hello)
  return 0;
}