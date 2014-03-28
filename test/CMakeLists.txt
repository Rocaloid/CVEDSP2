aux_source_directory(./TestCtrl Test1)
add_executable(TestCtrl ${Test1})
target_link_libraries(TestCtrl CVEDSP2)
target_link_libraries(TestCtrl RFNL)
target_link_libraries(TestCtrl RUtil2)
target_link_libraries(TestCtrl m)

add_test(TestCtrl TestCtrl)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-Ofast -I${TestDir}/TestCtrl -I${TopDir}/src")

