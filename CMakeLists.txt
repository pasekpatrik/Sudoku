cmake_minimum_required(VERSION 4.0)
project(mini_sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(mini_sudoku main.cpp
        model/Board.cpp
        controller/Controller.cpp
        view/Renderer.cpp
        view/InputHandler.cpp
        controller/Validator.cpp
)
