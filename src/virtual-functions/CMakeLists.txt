cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Зачем же использовать "virtual" в наследовании
add_executable(virtual-functions__1 virtual1.cpp)

# Что будет если использовать "virtual" + полиморфизм + виртуальный диструктор
add_executable(virtual-functions__2 virtual2.cpp)

# Зачем использовать "virtual" + полиморфизм + виртуальный деструктор
add_executable(virtual-functions__3 virtual3.cpp)

# "virtual" + правильный (с логической точки зрения) полиморфизм
add_executable(virtual-functions__4 virtual4.cpp)

# Чисто виртуальный диструктор
add_executable(virtual-functions__5 virtual5.cpp)

# Вызов виртуальных методов базового класса в классах наследниках
add_executable(virtual-functions__6 virtual6.cpp)

# Множественное наследование - простой пример
add_executable(virtual-functions__7 virtual7.cpp)

# Множественное наследование - вызов одинаковых методов из классов наследников
add_executable(virtual-functions__8 virtual8.cpp)

# Множественное (ромбовидное) наследование
add_executable(virtual-functions__9 virtual9.cpp)
