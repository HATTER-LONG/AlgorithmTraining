find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(01_TwoSum ${SRCFILELIST})

target_link_libraries(01_TwoSum
    Catch2::Catch2
    ${LOCAL_LINK_LIB}
    )
