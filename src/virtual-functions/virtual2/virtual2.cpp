#include <iostream>
/*
 *
 * Что будет если использовать "virtual" + полиморфизм + виртуальный диструктор
 *
 */
namespace virtual2 {
class Gun {
 public:
  Gun() {
    std::cout << "Gun()  ";
  }
  virtual ~Gun() {
    std::cout << "~Gun()  ";
  }
  virtual void use() {
    std::cout << "Gun()->use()  " << std::endl;
  }
};

class SweetGun : public Gun {
 public:
  SweetGun() {
    std::cout << "SweetGun()  ";
  }
  ~SweetGun() override {
    std::cout << "~SweetGun()  ";
  }

  void use() override {
    std::cout << "SweetGun()->use()  " << std::endl;
  }
};
}

using namespace virtual2;
int main() {
  Gun g;          //Gun()
  g.use();        //Gun()->use()

  SweetGun sg;    //Gun()  SweetGun()
  sg.use();       //Gun()  SweetGun()  SweetGun()->use()

  Gun *g1 = new SweetGun();   //Gun()  SweetGun()
  g1->use();                  //Gun()  SweetGun()  SweetGun()->use()

  delete (g1);    //~SweetGun()  ~Gun()     Утечка памяти устранена виртуальный деструктором базового класса.

  // SweetGun *g2 = new Gun(); -- Можно указывать только по цепочке снизу вверх

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  //~SweetGun()  ~Gun()  ~Gun()
}