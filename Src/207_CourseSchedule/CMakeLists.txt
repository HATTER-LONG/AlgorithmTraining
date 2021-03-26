find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(207_CourseSchedule ${SRCFILELIST})

target_link_libraries(207_CourseSchedule
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )