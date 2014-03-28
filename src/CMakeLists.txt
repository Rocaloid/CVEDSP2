aux_source_directory(./Interface SRC_LIST)
aux_source_directory(./Wave SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(CVEDSP2 SHARED ${SRC_LIST})
target_include_directories(CVEDSP2 PUBLIC "${CMAKE_SOURCE_DIR}/src")

install(FILES Include/CVEDSP2.h
              DESTINATION /usr/include/)

install(TARGETS CVEDSP2 LIBRARY DESTINATION /usr/lib)

