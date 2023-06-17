find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(15_3Sum
 ${SRCFILELIST}
 )

target_link_libraries(15_3Sum
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )
