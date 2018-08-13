#include <iostream>
#include <fstream>
/*
 *
 * Простой пример try-catch конструкции и exceptions
 *
 */

int main() {
  const std::string path = "file.txt";

  std::ifstream ifs;
  // По умолчанию exception отключены в классе ifstream... включаем вручную
  ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);

  try {
    std::cout << "Trying open file ..." << std::endl;   // Trying open file ...
    // Пытаемся открыть файл ... но его не существует - получаем 100% exception
    ifs.open(path);
    // Это не будет выполнено если выше был exception
    std::cout << "File was open !" << std::endl;
  } catch (const std::exception &ex) {
    // std::exception есть виртуальный метод what()
    std::cout << ex.what() << std::endl;          // basic_ios::clear: iostream error
    std::cout << "oops Exception!" << std::endl;  // oops Exception!
  }

  return 0;
}