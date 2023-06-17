find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(208_ImplementTrie_PrefixTree ${SRCFILELIST})

target_link_libraries(208_ImplementTrie_PrefixTree
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )