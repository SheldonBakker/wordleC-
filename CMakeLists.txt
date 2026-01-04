cmake_minimum_required(VERSION 3.21)
project(WordleCpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/GameState.cpp
    src/WordValidator.cpp
    src/ui/Renderer.cpp
    src/ui/InputHandler.cpp
    src/ui/Grid.cpp
    src/ui/Animation.cpp
)

if(WIN32)
    list(APPEND SOURCES resources/app.rc)
endif()

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/data
)

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Main)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)
