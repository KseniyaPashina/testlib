cmake_minimum_required(VERSION 3.8)

add_executable(Keyboard "main.cpp")
#add_executable(Keyboard "help.cpp")
target_link_libraries(Keyboard PUBLIC sfml-graphics sfml-window sfml-system)

add_executable(Board "keyboard_tests.cpp")
target_link_libraries(Board PUBLIC sfml-graphics sfml-window sfml-system doctest::doctest default)
doctest_discover_tests(Board)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/text.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Font/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Font/)