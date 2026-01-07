cmake_minimum_required(VERSION 3.10)
project(mini_sudoku)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mini_sudoku
        main.cpp
        model/Board.cpp
        controller/Controller.cpp
        controller/Validator.cpp
        view/Renderer.cpp
        view/InputHandler.cpp
        view/TerminalRawMode.hpp
        view/InputHandlerRaw.cpp
        view/InputHandlerRaw.hpp
)

target_include_directories(mini_sudoku PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/controller
        ${CMAKE_CURRENT_SOURCE_DIR}/view
)

enable_testing()

add_executable(sudoku_tests
        tests/test.cpp
        model/Board.cpp
        controller/Validator.cpp
        view/Renderer.cpp
        includes/catch.h
)

target_include_directories(sudoku_tests
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/controller
        ${CMAKE_CURRENT_SOURCE_DIR}/view
)

add_test(NAME SudokuTests COMMAND sudoku_tests)
