file(GLOB_RECURSE  SRC ./*.cpp ./*.h)

add_library(instructions SHARED ${SRC})

target_link_libraries(instructions native)