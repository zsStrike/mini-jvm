#add_subdirectory(heap)

file(GLOB_RECURSE SRC ./*.cpp ./*.h)

add_library(rtda SHARED ${SRC})

target_link_libraries(rtda classfile)
