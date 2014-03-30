aux_source_directory(./TestCtrl Test1)
add_executable(TestCtrl ${Test1})
target_link_libraries(TestCtrl CVEDSP2)
target_link_libraries(TestCtrl RFNL)
target_link_libraries(TestCtrl RUtil2)
target_link_libraries(TestCtrl m)

aux_source_directory(./TestDSP Test2)
add_executable(TestDSP ${Test2})
target_link_libraries(TestDSP CVEDSP2)
target_link_libraries(TestDSP RFNL)
target_link_libraries(TestDSP RUtil2)
target_link_libraries(TestDSP m)

add_test(TestCtrl TestCtrl)
add_test(TestDSP TestDSP)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-Ofast -I${TestDir}/TestCtrl -I${TopDir}/src")

