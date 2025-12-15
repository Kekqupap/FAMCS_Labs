include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)
include(googletest)

add_executable(calc_tests test_calculator.cpp)
target_link_libraries(calc_tests calc GTest::gtest_main)

gtest_discover_tests(calc_tests)