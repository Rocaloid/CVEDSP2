aux_source_directory(./Interface SRC_LIST)
aux_source_directory(./Container SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(CVEDSP2 SHARED ${SRC_LIST})
include_directories(CVEDSP2 PUBLIC "${CMAKE_SOURCE_DIR}/src")

file(GLOB Header_Interface_RFNLInterface "Interface/RFNLInterface/*.h")
file(GLOB Header_Container "Container/*.h")
install(FILES Interface/Setting.h
              DESTINATION /usr/include/CVEDSP2/Interface)
install(FILES ${Header_Interface_RFNLInterface}
              DESTINATION /usr/include/CVEDSP2/Interface/RFNLInterface)
install(FILES ${Header_Container}
              DESTINATION /usr/include/CVEDSP2/Container)
install(FILES Include/CVEDSP2.h
              DESTINATION /usr/include/)

install(TARGETS CVEDSP2 LIBRARY DESTINATION /usr/lib)

