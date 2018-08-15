cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Простой пример try-catch конструкции и exceptions
add_executable(exceptions__1 exceptions_1.cpp)

# throw, exception и несколько catch
add_executable(exceptions__2 exceptions_2.cpp)

# Свой простой класс exceptions
add_executable(exceptions__3 exceptions_3.cpp)

# Делегирующий конструктор
add_executable(delegating-constructors__1 delegating-constructors_1.cpp)

# Приведение типов в стиле "С"
add_executable(cast__1 cast_1.cpp)

# Функторы
add_executable(functor__1 functor_1.cpp)

# Предикаты
add_executable(predicate__1 predicate_1.cpp)

# Перегрузка функций
add_executable(func-overload__1 function-overload_1.cpp)

# Преобразования в С++
add_executable(cast__2 cast_2.cpp)
