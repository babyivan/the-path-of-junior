cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Простой пример try-catch конструкции и exceptions
add_executable(exceptions__1 exceptions_1.cpp)

# exceptions и throw + несколько catch
add_executable(exceptions__2 exceptions_2.cpp)

# Свой простой класс exceptions
add_executable(exceptions__3 exceptions_3.cpp)

# Делегирующий конструктор
add_executable(delegating-constructors__1 delegating-constructors.cpp)

# Приведение типов в стиле "С"
add_executable(cast__1 cast_1.cpp)