find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(46_Permutations ${SRCFILELIST})

target_link_libraries(46_Permutations
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )