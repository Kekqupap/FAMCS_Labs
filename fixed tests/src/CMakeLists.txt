add_library(calc calculator.cpp)
add_executable(calc_app main.cpp)
target_link_libraries(calc_app calc)
