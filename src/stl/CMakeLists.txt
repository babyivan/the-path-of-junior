cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Vector
add_executable(stl__1 stl_1.cpp stl_8.cpp)

# Итераторы
add_executable(stl__2 stl_2.cpp)

# List
add_executable(stl__3 stl_3.cpp)

# Forward list (С++11)
add_executable(stl__4 stl_4.cpp)

# Array (С++11)
add_executable(stl__5 stl_5.cpp)

# Deque
add_executable(stl__6 stl_6.cpp)

# Set/Multiset
add_executable(stl__7 stl_7.cpp)

# Map/Multimap
add_executable(stl__8 stl_8.cpp)

# Stack
add_executable(stl__9 stl_9.cpp)

# Queue, Priority queue
add_executable(stl__10 stl_10.cpp)

# STL - Алгоритмы
add_executable(stl_algorithms stl_algorithms.cpp)
