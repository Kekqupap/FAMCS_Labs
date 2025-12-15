cmake_minimum_required(VERSION 3.14)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Загрузка GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Включаем модуль GoogleTest
include(GoogleTest)

# Основная библиотека
add_library(parser_lib src/Par.cpp)
target_include_directories(parser_lib PUBLIC include)

# Основное приложение
add_executable(calc_app app/main.cpp)
target_link_libraries(calc_app parser_lib)

# Тесты
add_executable(calc_tests tests/tests.cpp)
target_link_libraries(calc_tests parser_lib gtest gtest_main)
target_include_directories(calc_tests PRIVATE include)

# Включаем поддержку тестирования
enable_testing()

# Автоматически обнаруживаем все тесты и добавляем их в CTest как отдельные тесты
gtest_discover_tests(calc_tests
  EXTRA_ARGS "--gtest_output=xml:${CMAKE_BINARY_DIR}/test_results.xml"
)