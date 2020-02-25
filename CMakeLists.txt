cmake_minimum_required(VERSION 3.15)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c)
add_executable(lab8 lab1/lab8.c)
add_executable(lab5 lab1/lab5.c)
add_executable(lab23 lab1/lab23.c)

add_executable(lab2.14 lab2/lab14.c)
add_executable(lab2.37 lab2/lab2.37.c)
add_executable(lab2new lab2/lab2.37new.c)

add_executable(lab3.18a lab3/lab3.18a.c)
add_executable(lab3.18b lab3/lab3.18b.c)

add_executable(structures test/structures.c)
add_executable(stack test/stack.c test/stack.h)





