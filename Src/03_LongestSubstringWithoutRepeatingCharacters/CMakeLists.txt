find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
   )

add_executable(LongestSubstringWithoutRepeatingCharacters ${SRCFILELIST})

target_link_libraries(LongestSubstringWithoutRepeatingCharacters
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB} 
    )