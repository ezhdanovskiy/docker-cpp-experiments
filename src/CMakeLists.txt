cmake_minimum_required (VERSION 3.2)
project (docker_cpp_experiments)

# используем C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fPIC")

# исполняемый файл нашего приложения
add_executable (app main.cpp Calc.h Calc.cpp)

# включаем CTest
enable_testing()

# в качестве фреймворка для тестирования используем GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# исполняемый файл тестов
add_executable(app_test CalcTest.cpp Calc.h Calc.cpp)
target_link_libraries(app_test ${GTEST_LIBRARIES} pthread)

# добавим этот файл в тестовый набор CTest
add_test(NAME CalcTest COMMAND app_test)