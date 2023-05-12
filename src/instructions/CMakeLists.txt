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

add_library(instructions SHARED ${SRC} control/return.h references/invokestatic.h references/invokevirtual.h references/invokeinterface.h base/class_init_logic.h)

target_link_libraries(instructions rtda)