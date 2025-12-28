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
        resource/sudoku1.txt
        resource/sudoku2.txt
        resource/sudoku3.txt
)

target_include_directories(mini_sudoku PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/controller
        ${CMAKE_CURRENT_SOURCE_DIR}/view
)
