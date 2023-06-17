find_package(Catch2 REQUIRED CONFIG)

FILE(GLOB SRCFILELIST
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(X_Template ${SRCFILELIST})

target_link_libraries(X_Template
    Catch2::Catch2WithMain
    ${LOCAL_LINK_LIB}
)
