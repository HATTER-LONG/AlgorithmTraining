find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(114_FlattenBinaryTreetoLinkedList ${SRCFILELIST})

target_link_libraries(114_FlattenBinaryTreetoLinkedList
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )