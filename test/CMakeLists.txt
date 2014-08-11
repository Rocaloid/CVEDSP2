aux_source_directory(./TestCtrl Test1)
add_executable(_TestCtrl ${Test1})
target_link_libraries(_TestCtrl CVEDSP2)
target_link_libraries(_TestCtrl RFNL)
target_link_libraries(_TestCtrl m)

aux_source_directory(./TestDSP Test2)
add_executable(_TestDSP ${Test2})
target_link_libraries(_TestDSP CVEDSP2)
target_link_libraries(_TestDSP RFNL)
target_link_libraries(_TestDSP m)

aux_source_directory(./TestIterfector Test3)
add_executable(_TestIterfector ${Test3})
target_link_libraries(_TestIterfector CVEDSP2)
target_link_libraries(_TestIterfector RFNL)
target_link_libraries(_TestIterfector m)

add_test(TestCtrl _TestCtrl)
add_test(TestDSP _TestDSP)
add_test(TestIterfector _TestIterfector)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TestDir}/TestCtrl -I${TopDir}/src")

