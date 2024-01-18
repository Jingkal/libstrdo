if (APPLE)
    set(iconv_search_dir /opt/homebrew/Cellar/libiconv)
    file(GLOB iconv_dirs LIST_DIRECTORIES true ${iconv_search_dir}/*)
    list(SORT iconv_dirs COMPARE NATURAL ORDER DESCENDING)
    list(GET iconv_dirs 0 iconv_DIR)
else()
    set(iconv_search_dir /usr)
endif()

message("search dir: ${iconv_search_dir}")
message("iconv dirs: ${iconv_DIR}")

add_library(iconv IMPORTED STATIC)
set_target_properties(iconv PROPERTIES
    IMPORTED_LOCATION ${iconv_DIR}/lib/libiconv.a)
target_include_directories(iconv
    INTERFACE ${iconv_DIR}/include)
set(iconv_FOUND true)
