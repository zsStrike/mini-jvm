cmake_minimum_required(VERSION 3.10)

project(mini-jvm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILECOMMANDS ON)
# set(CMAKE_CXX_FLAGS "-lpthread")
# set(CMAKE_CXX_FLAGS "-DBOOST_LOG_DYN_LINK -lboost_program_options -lboost_log -lboost_log_setup -lpthread")

add_subdirectory(src)
add_subdirectory(test)