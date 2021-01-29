find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(11_ContainerWithMostWater
 ${SRCFILELIST}
 )

target_link_libraries(11_ContainerWithMostWater
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )