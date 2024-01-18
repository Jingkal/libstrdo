find_package(Catch2 CONFIG REQUIRED
    HINTS /usr/lib/cmake/Catch2
)

file(GLOB testsrcfiles ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
message("PROJECT name: ${PROJECT_NAME}")

foreach(tfile IN LISTS testsrcfiles)
    get_filename_component(tarname ${tfile} NAME_WE)
    message(" >>> ${tfile} -> ${tarname}")
    set(tarname "test-${tarname}")
    add_executable(${tarname} ${tfile})
    target_link_libraries(${tarname} PUBLIC strdo Catch2::Catch2WithMain)
endforeach()
