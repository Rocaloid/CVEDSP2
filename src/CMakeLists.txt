aux_source_directory(./Interface SRC_LIST)
aux_source_directory(./Container SRC_LIST)
aux_source_directory(./List SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TopDir}/src")

add_library(CVEDSP2 SHARED ${SRC_LIST})
include_directories(CVEDSP2 PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(CVEDSP2 RFNL)
target_link_libraries(CVEDSP2 m)

file(GLOB Header_Interface_RFNLInterface "Interface/RFNLInterface/*.h")
file(GLOB Header_Container "Container/*.h")
file(GLOB Header_List "List/*.h")
install(FILES Interface/Setting.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVEDSP2/Interface)
install(FILES ${Header_Interface_RFNLInterface}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVEDSP2/Interface/RFNLInterface)
install(FILES ${Header_Container}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVEDSP2/Container)
install(FILES ${Header_List}
              List/_SizeNumList.rc
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVEDSP2/List)
install(FILES Include/CVEDSP2.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

install(TARGETS CVEDSP2 LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)