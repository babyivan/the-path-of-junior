cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Зачем же использовать "virtual" в наследовании
add_executable(virtual-functions__1 virtual_1.cpp)

# Что будет если использовать "virtual" + полиморфизм + виртуальный диструктор
add_executable(virtual-functions__2 virtual_2.cpp)

# Зачем использовать "virtual" + полиморфизм + виртуальный деструктор
add_executable(virtual-functions__3 virtual_3.cpp)

# "virtual" + правильный (с логической точки зрения) полиморфизм
add_executable(virtual-functions__4 virtual_4.cpp)

# Чисто виртуальный диструктор
add_executable(virtual-functions__5 virtual_5.cpp)

# Вызов виртуальных методов базового класса в классах наследниках
add_executable(virtual-functions__6 virtual_6.cpp)

# Множественное наследование - простой пример
add_executable(virtual-functions__7 virtual_7.cpp)

# Множественное наследование - вызов одинаковых методов из классов наследников
add_executable(virtual-functions__8 virtual_8.cpp)

# Множественное (ромбовидное) наследование
add_executable(virtual-functions__9 virtual_9.cpp)
