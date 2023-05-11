aux_source_directory(. DIR_SRC)

add_library(classpath SHARED ${DIR_SRC})
target_link_libraries(classpath zip boost_filesystem)