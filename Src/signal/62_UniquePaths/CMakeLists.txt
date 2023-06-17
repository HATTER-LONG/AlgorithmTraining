find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(62_UniquePaths ${SRCFILELIST})

target_link_libraries(62_UniquePaths
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )