cmake_minimum_required(VERSION 3.16)
project(demo_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 所有可执行文件统一输出到 build/bin，保持根目录与 src 整洁
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 每个 src/*.cpp 自动生成一个同名可执行目标。
# 新增练习文件后无需修改本文件。
file(GLOB EXERCISE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# 忽略 Code Runner 等工具生成的临时文件
list(FILTER EXERCISE_SOURCES EXCLUDE REGEX "tempCodeRunnerFile.*\\.cpp$")

foreach(source ${EXERCISE_SOURCES})
  get_filename_component(target ${source} NAME_WE)
  add_executable(${target} ${source})
endforeach()
