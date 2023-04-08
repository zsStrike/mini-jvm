aux_source_directory(. DIR_SRC)

add_library(classfile ${DIR_SRC})
# target_link_libraries(classfile zip boost_filesystem)