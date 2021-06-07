cmake_minimum_required(VERSION 3.19)
project(sko_database)

set(CMAKE_CXX_STANDARD 11)

add_executable(sko_database test.cpp bookbase.cpp bookbase.h writtenmedia.cpp writtenmedia.h user.cpp user.h userbase.cpp userbase.h book.cpp book.h writtenmedia.cpp)
