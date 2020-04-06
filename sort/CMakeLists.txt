# CMakeList.txt: проект CMake для CMakeLabs; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.

# TODO: Добавьте тесты и целевые объекты, если это необходимо.


project(TMP CXX)

if("${CMAKE_CXX_COMPILER_ID})" STREQUAL "GNU")#gcc

add_compile_options(-Wall -Wextra -Wpedantic)

elseif("${CMAKE_CXX_COMPILER_ID})" STREQUAL "MSVC")# Compiler by Microsoft

add_compile_options(/W4 /D_CRT_SECURE_NO_WARNINGS) #четвертый уровень предупреждения

endif()

add_subdirectory(libutils)

add_subdirectory(lab-6)
