aux_source_directory(./Interface SRC_LIST)
aux_source_directory(./Container SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(CVEDSP2 SHARED ${SRC_LIST})
include_directories(CVEDSP2 PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(CVEDSP2 RFNL)
target_link_libraries(CVEDSP2 m)

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

if(CYGWIN OR WIN32)
    message(STATUS "You are compiling this project as COFF.")
    install(TARGETS CVEDSP2 DESTINATION /usr/lib)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "You are compiling this project as 64bit.")
    install(TARGETS CVEDSP2 DESTINATION /usr/lib64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(STATUS "You are compiling this project as 32bit.")
    install(TARGETS CVEDSP2 DESTINATION /usr/lib)
else()
    message(FATAL_ERROR "Your system is unsupported!")
endif()

