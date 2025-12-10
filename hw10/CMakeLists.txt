cmake_minimum_required(VERSION 3.28)

project(MyCProject LANGUAGES C)


# set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(TASKS task1 task2 task3 task4 task5 task6 task7 task8 task9 task10
          task11 task12 task13 task14 task15 task16 task17 task18 task19
          task20 task21 task22)
          
foreach(task IN LISTS TASKS)
    add_executable(${task} ${task}.c)
endforeach()
