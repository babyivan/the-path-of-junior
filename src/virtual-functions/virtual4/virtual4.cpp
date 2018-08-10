#include <iostream>
/*
 *
 * "virtual" + правильный (с логической точки зрения) полиморфизм
 *
 */
namespace virtual4 {
// Абстрактный класс для всего оружия
class weapon {
 public:
  virtual void use() =0;
};

class Gun : public weapon {
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
  ~SweetGun() {
    std::cout << "~SweetGun()  ";
  }

  void use() override {
    std::cout << "SweetGun()->use()  " << std::endl;
  }
};

class Bazooka : public weapon {
 public:
  Bazooka() {
    std::cout << "Bazooka()  ";
  }
  ~Bazooka() {
    std::cout << "~Bazooka()  ";
  }

  void use() override {
    std::cout << "Bazooka()->use()  " << std::endl;
  }
};

class Player {
 public:
  void shoot(weapon *w) {
    w->use();
  }
};
}

using namespace virtual4;
int main() {

  //weapon w;     //Ошибка - класс абстрактный

  SweetGun sg;    //Gun()  SweetGun()
  Bazooka b;      //Bazooka()

  weapon *pb = &b;  // Все ок, благодоря полиморфизму

  Player p;
  p.shoot(&sg);   //SweetGun()->use()
  p.shoot(pb);    //Bazooka()->use()

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  //~Bazooka()  ~SweetGun()  ~Gun()
}