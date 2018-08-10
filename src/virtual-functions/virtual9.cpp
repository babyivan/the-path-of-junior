#include <iostream>
/*
 *
 * Множественное (ромбовидное) наследование
 *
 */
namespace virtual9_1 {
class component {
 public:
  explicit component(std::string component_name) {
    this->component_name = component_name;
    std::cout << "component()  ";
  }
 private:
  std::string component_name;
};

class gpu : public component {
 public:
  explicit gpu(std::string component_name)
      : component(component_name) {
    std::cout << "gpu()  ";
  }
};

class memory : public component {
 public:
  explicit memory(std::string component_name)
      : component(component_name) {
    std::cout << "memory()  ";
  }
};
class graphic_card : public gpu, public memory {
 public:
  explicit graphic_card(std::string gpu_component_name, std::string memory_component_name)
      : gpu(gpu_component_name),
        memory(memory_component_name) {
    std::cout << "graphic_card()  ";
  }
};

class character {
 public:
  explicit character() {
    std::cout << "character()  ";
    health = 100;
  }
 protected:
  const int &get_health() const {
    return health;
  }
  void set_health(int new_health) {
    health = new_health;
  }
 private:
  int health;
};
// Раса
class human : public character {
 public:
  explicit human() {
    std::cout << "human()  ";
  }
};
// Класс
class robot : public character {
 public:
  explicit robot() {
    std::cout << "robot()  ";
  }
};

class android : public human, public robot {
 public:
  explicit android() {
    std::cout << "android()  ";
  }
  // Функция нанесения урона игроку
  void apply_damage(int damage) {
    // Неоднозначность вызова...
    // int new_health = get_health() + damage;
    // set_health(new_health);
  }
  // Вывод информации о здоровье игрока на экран
  void print_health() {
    // Неоднозначность вызова...
    // std::cout << "HP: " << get_health() << "  ";
  }
};
}
///////////////////////////////
namespace virtual9_2 {
class character {
 public:
  explicit character() {
    std::cout << "character()  ";
    health = 100;
  }
 protected:
  const int &get_health() const {
    return health;
  }
  void set_health(int new_health) {
    health = new_health;
  }
 private:
  int health;
};
// Раса
class human : public virtual character {
 public:
  explicit human() {
    std::cout << "human()  ";
  }
};
// Класс
class robot : public virtual character {
 public:
  explicit robot() {
    std::cout << "robot()  ";
  }
};

class android : public human, public robot {
 public:
  explicit android() {
    std::cout << "android()  ";
  }
  // Функция нанесения урона игроку
  void apply_damage(int damage) {
    int new_health = get_health() + damage;
    set_health(new_health);
  }
  // Вывод информации о здоровье игрока на экран
  void print_health() {
    std::cout << "HP: " << get_health() << "  ";
  }
};
}

int main() {
  {
    using namespace virtual9_1;

    // В данном случае нам нужно чтобы "component" был в "gpu" и "memory"
    graphic_card gc("nvidia", "micron");    //component()  gpu()  component()  memory()  graphic_card()

    // Представим что у нас ммо-игра. Есть игрок расы "человек" и класса "робот". Оба наследуються от "character"..
    // ... class human : public character ... class robot : public virtual character ...

    android a1;             // character()  human()  character()  robot()  android()
    a1.apply_damage(-20);   // error: reference to 'get_health' is ambiguous
                            // In member function 'void virtual9_1::android::apply_damage(int)'
    a1.print_health();      // Не выполниться
  }

  /*
  * а это значит что "health" есть у "robot" и "human". Теперь вопрос - как нам изменить health в класе "android" ?
  * если мы видим что "character" есть там и там ?
  *
  * Ответ: используем виртуальное наследование !
  * ... class human : public "virtual" character ...
  * ... class robot : public "virtual" character ...
  */
  {
    using namespace virtual9_2;

    android a2;             // character()  human() robot()  android()
    a2.print_health();      // HP: 100
    a2.apply_damage(-20);   // OK
    a2.print_health();      // HP: 80
  }

  std::cout << std::endl << "----------------" << std::endl;
  return 0;
}
