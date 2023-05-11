file(GLOB_RECURSE  SRC ./*.cpp ./*.h)


#add_library(instructions ${SRC}
#        ../rtda/heap/constant_pool.h
#        ../rtda/heap/constant_pool.cpp
#        ../rtda/heap/Object.h
#        ../rtda/heap/Object.cpp
#        ../rtda/heap/cp_symref.h
#        ../rtda/heap/cp_symref.cpp
#        ../rtda/heap/class_member.h
#        ../rtda/heap/class_member.cpp)

add_library(instructions SHARED ${SRC} references/invokespecial.h)

target_link_libraries(instructions rtda)