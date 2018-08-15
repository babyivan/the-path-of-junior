/*
 * Зачем же использовать "virtual" в наследовании
 */

#include <iostream>

class Gun {
 public:
  Gun() {
    std::cout << "Gun()  ";
  }
  ~Gun() {
    std::cout << "~Gun()  ";
  }
  void use() {
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

  void use() {
    std::cout << "SweetGun()->use()  " << std::endl;
  }
};

int main() {
  Gun g;          //Gun()
  g.use();        //Gun()->use()

  SweetGun sg;    //Gun()  SweetGun()
  sg.use();       //Gun()  SweetGun()  SweetGun()->use()

  Gun *g1 = new SweetGun();   //Gun()  SweetGun()
  g1->use();                  //Gun()  SweetGun()  Gun()->use()   Хотя создаем "SweetGun"...

  delete (g1);    //~Gun()     Тут утечка памяти. SweetGun() не будет уничтожен если диструктор базового класса не виртуален.
  //           при инициализации через "new" и инициализации через базовый класс.

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
  //~SweetGun()  ~Gun()  ~Gun()
}
