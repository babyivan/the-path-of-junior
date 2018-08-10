#include <iostream>
/*
 *
 * "virtual" + правильный (с логической точки зрения) полиморфизм
 * в с++ слова "интерфейс" официально нет, но, "weapon" можно считать (если смотреть на другие языки программирования) за интерфейс
 * (класс в котором все абстрактное и не имеет любой реализации)
 *
 */

// Абстрактный класс / Интрейфейс для всего оружия
class weapon {
 public:
  virtual void use() =0;
};
// Класс пистолет
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
// Класс навороченый пистолет (наследуется от пистолета а не от weapon)
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
// Класс нож
class Knife : public weapon {
 public:
  Knife() {
    std::cout << "Knife()  ";
  }
  ~Knife() {
    std::cout << "Knife  ";
  }

  void use() override {
    std::cout << "Knife()->use()  " << std::endl;
  }
};

class Player {
 public:
  void shoot(weapon *w) {
    w->use();
  }
};

int main() {

  //weapon w;     //Ошибка - класс абстрактный

  SweetGun sg;    //Gun()  SweetGun()
  Knife b;        //Knife()

  weapon *pb = &b;  // Все ок, благодаря полиморфизму

  Player p;
  p.shoot(&sg);   //SweetGun()->use()
  p.shoot(pb);    //Knife()->use()

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  //Knife  ~SweetGun()  ~Gun()
}
