cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Шаблонны функций
add_executable(templates__1 templates_1.cpp)

# Шаблоны класов
add_executable(templates__2 templates_2.cpp)

# Наследование шаблонов класса
add_executable(templates__3 templates_3.cpp)

# Специализация шаблонов класса
add_executable(templates__4 templates_4.cpp)