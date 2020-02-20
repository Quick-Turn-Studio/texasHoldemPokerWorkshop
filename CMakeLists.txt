cmake_minimum_required(VERSION 3.10)

set(APP_NAME TexasHoldemPokerGame)

project(${APP_NAME})

add_subdirectory(third-party)
add_subdirectory(src)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME} PRIVATE TexasHoldemPokerLib)