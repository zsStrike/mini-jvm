add_subdirectory(log)
add_subdirectory(classpath)

add_executable(main main.cpp)
target_link_libraries(main boost_program_options classpath)