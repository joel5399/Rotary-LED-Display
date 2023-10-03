cmake_minimum_required(VERSION 3.0.2)
project(display_rpi)

## Additional CMake Modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

## Compile as C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
## enforcing cleaner code.
add_definitions(-Wall -Werror -Wno-error=comment)

find_package(pigpio REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${pigpio_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(
  ${PROJECT_NAME}
  src/hardware_controller.cpp
  src/main.cpp
  src/pixel.cpp
  src/rpi_dotstar.cpp
  src/rotation_controller.cpp
  src/image_processor.cpp
)

add_dependencies(${PROJECT_NAME} pigpio)

target_link_libraries(
  ${PROJECT_NAME}
  ${pigpio_LIBRARIES}
  pthread
  ${OpenCV_LIBS}
)
