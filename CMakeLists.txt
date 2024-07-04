# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required(VERSION 3.10)

project ("Interpreter")
set(CMAKE_CXX_STANDARD 14)
# Включите подпроекты.
add_subdirectory ("Interpreter")
