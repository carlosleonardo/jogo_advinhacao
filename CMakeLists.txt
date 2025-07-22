cmake_minimum_required(VERSION 3.31)
project(jogo_advinhacao)

set(CMAKE_CXX_STANDARD 20)

add_executable(jogo_advinhacao main.cpp)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(jogo_advinhacao PRIVATE fmt::fmt)