# CMakeList.txt: проект CMake для Interpreter; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Interpreter "Interpreter.cpp" "Interpreter.h" "lexer.h" "lexer.cpp" "parser.h" "parser.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Interpreter PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
