find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(76_MinimumWindowSubstring ${SRCFILELIST})

target_link_libraries(76_MinimumWindowSubstring
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )