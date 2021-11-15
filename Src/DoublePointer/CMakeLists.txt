find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(DoublePointer ${SRCFILELIST})

target_link_libraries(DoublePointer
    Catch2::Catch2
    ${LOCAL_LINK_LIB}
    )
