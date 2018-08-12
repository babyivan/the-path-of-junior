#include <iostream>
/*
 *
 * Зачем использовать "virtual" + полиморфизм + виртуальный деструктор
 * Смотреть класс "Player"
 *
 */
namespace virtual3 {
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

class Bazooka : public Gun {
 public:
  Bazooka() {
    std::cout << "Bazooka()  ";
  }
  ~Bazooka() override {
    std::cout << "~Bazooka()  ";
  }

  void use() override {
    std::cout << "Bazooka()->use()  " << std::endl;
  }
};

class Player {
 public:
  void shoot(Gun *gun) {
    gun->use();
  }
};
}

using namespace virtual3;
int main() {
  Gun g;          //Gun()
  g.use();        //Gun()->use()

  SweetGun sg;    //Gun()  SweetGun()
  sg.use();       //Gun()  SweetGun()  SweetGun()->use()

  Gun *g1 = new SweetGun();   //Gun()  SweetGun()
  g1->use();                  //Gun()  SweetGun()  SweetGun()->use()
  delete (g1);    //~SweetGun()  ~Gun()

  // SweetGun *g2 = new Gun(); -- Можно указывать только по цепочке снизу вверх

  Bazooka b;    //Gun() Bazooka()
  b.use();      //Gun() Bazooka()  Bazooka()->use()

  Player p;
  p.shoot(&g);        //Gun()->use()
  p.shoot(&sg);       //SweetGun()->use()
  p.shoot(&b);        //Bazooka()->use()

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  //~Bazooka()  ~Gun()  ~SweetGun()  ~Gun()  ~Gun()
}