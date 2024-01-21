if(NOT Catch2_FOUND)
    message(WARNING ">>>> Catch2 NOT loaded. Test Aborted!")
    return()
endif()

message(STATUS ">>>> Making tests:")

# get all test source files
file(GLOB srcfiles ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
foreach(filename IN LISTS srcfiles)
    get_filename_component(testname ${filename} NAME_WE)
    set(testname test-${testname})
    message(STATUS ">>>>>>> +test: [${testname}] from\n\t\t\t${filename}")
    add_executable(${testname} ${filename})
    target_link_libraries(${testname} ${PROJECT_NAME} Catch2::Catch2WithMain)
endforeach()
