cmake_minimum_required(VERSION 3.8)
project(Wzorce2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pamiatka.cpp Pamiatka.h Chain.cpp Chain.h Boats.cpp Boats.h Observer.cpp Observer.h Visitor.cpp Visitor.h Mediator.cpp Mediator.h Strategy.cpp Strategy.h Proxy.cpp Proxy.h Command.cpp Command.h)
add_executable(Wzorce2 ${SOURCE_FILES})