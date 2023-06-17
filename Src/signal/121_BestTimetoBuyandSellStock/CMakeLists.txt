find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(121_BestTimetoBuyandSellStock ${SRCFILELIST})

target_link_libraries(121_BestTimetoBuyandSellStock
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )