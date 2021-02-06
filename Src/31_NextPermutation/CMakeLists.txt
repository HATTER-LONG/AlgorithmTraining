find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(31_NextPermutation ${SRCFILELIST})

target_link_libraries(31_NextPermutation
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )