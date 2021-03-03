find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(101_SymmetricTree ${SRCFILELIST})

target_link_libraries(101_SymmetricTree
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )