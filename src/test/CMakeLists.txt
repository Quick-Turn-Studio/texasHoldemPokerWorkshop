set(TEST_NAME TexasHoldemPokerTests)

project(${TEST_NAME})

aux_source_directory(. TEST_FILES)

add_executable(${TEST_NAME} ${TEST_FILES})

target_include_directories(${TEST_NAME} PRIVATE ${gmock_SOURCE_DIR}/include)
target_include_directories(${TEST_NAME} PRIVATE ${gtest_SOURCE_DIR}/include)

target_link_libraries(${TEST_NAME} PRIVATE TexasHoldemPokerLib)
target_link_libraries(${TEST_NAME} PRIVATE gmock gmock_main)