#include <iostream>
/*
 *
 * Делегирующий конструктор
 *
 */
namespace delegating_constructors {
class human {
 public:
  human(std::string name) {
    std::cout << "human(std::string name) " << std::endl;
    this->name = name;
    this->age = 0;
    this->weight = 0;
  }
  human(std::string name, int age)
      : human(name) {
    std::cout << "human(std::string name, int age) " << std::endl;
    this->age = age;
  }
  human(std::string name, int age, int weight)
      : human(name, age) {
    std::cout << "human(std::string name, int age, int weight) " << std::endl;
    this->weight = weight;
  }
 private:
  std::string name;
  int age;
  int weight;
};
}

using namespace delegating_constructors;
int main() {
  human h("teddy");             //human(std::string name)
  human h1("teddy", 10);        //human(std::string name) human(std::string name, int age)
  human h2("teddy", 10, 23);    //human(std::string name) human(std::string name, int age) human(std::string name, int age, int weight)

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
}