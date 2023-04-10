aux_source_directory(. DIR_SRC)

add_library(interpreter ${DIR_SRC})

target_link_libraries(interpreter instructions rtda classfile)