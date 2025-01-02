cmake_minimum_required(VERSION 3.30)


set(CMAKE_CXX_STANDARD 20)
set(CMKAE_CXX_STANDARD_REQUIRED ON)

project(LottoNumberGiver)

add_executable(LottoNumberGiver Main.cpp)

add_custom_command(
    TARGET LottoNumberGiver  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Src/Archive  # Source Folder
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying Folder to the build directory"
)

add_custom_command(
    TARGET LottoNumberGiver  # Replace with your target name
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Src/Given  # Source Folder
        ${PROJECT_BINARY_DIR}/Debug  # Destination directory
    COMMENT "Copying Folder to the build directory"
)