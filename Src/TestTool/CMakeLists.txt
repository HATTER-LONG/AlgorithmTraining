find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/../main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(TestTool ${SRCFILELIST})
target_link_libraries(TestTool
    Catch2::Catch2
    ${LOCAL_LINK_LIB} 
    )
