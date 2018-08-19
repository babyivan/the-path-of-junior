/*
 * Предикаты
 * по факту функция которая должна возращать bool значение
 * бывают: "унарные" - 1 вход. параметр и "бинарные" - 2 вход. параметра
 */

#include <iostream>
#include <algorithm>
#include <vector>

// Простенький предикат (унарный)
bool greater_then_zero(const int &a) {
  return a > 0;
}

// Более реальный пример предиката
class person {
 public:
  person(std::string name, int score) {
    this->name = name;
    this->score = score;
  }

  bool operator()(const person &p) {
    return p.score > 150;
  }
 private:
  std::string name;
  int score;
};

int main() {
  std::vector<int> v1 = {1, -33, -12, 28, 0, 94, 7};
  long long result1 = std::count_if(v1.begin(), v1.end(), greater_then_zero);
  std::cout << "result : " << result1 << std::endl;   //result : 4

  std::vector<person> v2{
      person("Дмитрий", 69),
      person("Лола", 164),
      person("Василий", 120),
      person("Микки", 156),
      person("Мария", 202),
      person("Иван", 185),
      person("Евгений", 151),
      person("Владислав", 133),
  };

  long long result2 = std::count_if(v2.begin(), v2.end(), v2.front());
  std::cout << "result : " << result2 << std::endl;   //result : 5
  return 0;
}
