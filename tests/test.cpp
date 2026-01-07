#define CATCH_CONFIG_MAIN
#include "../includes/catch.h"

#include "../model/Board.hpp"
#include "../controller/Validator.hpp"
#include "../view/Renderer.hpp"

// =========================
//  TESTS BOARD
// =========================
TEST_CASE("Board – změna hodnoty a načítání ze souboru", "[board]") {

    Board board;
    board.setBoardSize(FOUR);
    board.createBoard();

    SECTION("Změna hodnoty na desce") {
        REQUIRE(board.changeBoard(1, 2, 7) == true);
        REQUIRE(board.getBoard()[1][2] == 7);
    }

    SECTION("Načtení desky ze souboru") {
        std::ofstream f("test_board.txt");
        f << "0 0 5\n1 1 9\n";
        f.close();

        REQUIRE(board.loadBoard("test_board.txt") == true);
        REQUIRE(board.getBoard()[0][0] == 5);
        REQUIRE(board.getBoard()[1][1] == 9);
    }

    SECTION("Načtení neexistujícího souboru") {
        REQUIRE(board.loadBoard("neexistuje.txt") == false);
    }
}


// =========================
//  TESTS VALIDATOR
// =========================

TEST_CASE("Validator – validace pozic", "[validator]") {

    Board board;
    board.setBoardSize(FOUR);
    board.createBoard();

    Validator val;

    SECTION("Validní tah do prázdného pole") {
        REQUIRE(val.isCorrectPosition(1, 1, board, 3) == true);
    }

    SECTION("Nevalidní – pozice mimo rozsah") {
        REQUIRE(val.isCorrectPosition(-1, 0, board, 3) == false);
        REQUIRE(val.isCorrectPosition(10, 10, board, 3) == false);
    }

    SECTION("Nevalidní – pole není prázdné") {
        board.changeBoard(2, 2, 4);
        REQUIRE(val.isCorrectPosition(2, 2, board, 3) == false);
    }

    SECTION("Nevalidní – duplicitní číslo v řádku") {
        board.changeBoard(0, 1, 2);
        REQUIRE(val.isCorrectPosition(0, 3, board, 2) == false);
    }

    SECTION("Nevalidní – duplicitní číslo ve sloupci") {
        board.changeBoard(1, 0, 3);
        REQUIRE(val.isCorrectPosition(3, 0, board, 3) == false);
    }

    SECTION("Nevalidní – duplicitní číslo v bloku") {
        board.changeBoard(0, 0, 1);
        REQUIRE(val.isCorrectPosition(1, 1, board, 1) == false);
    }
}

TEST_CASE("Validator – kontrola dokončení hry", "[validator]") {

    Validator val;
    Board board;

    board.setBoardSize(FOUR);
    board.createBoard();

    SECTION("Deska není vyřešená – obsahuje nuly") {
        REQUIRE(val.isSudokuSolved(board.getBoard()) == false);
    }

    SECTION("Deska je vyřešená – žádné nuly") {
        auto full = std::vector<std::vector<int>>{
            {1,2,3,4},
            {3,4,1,2},
            {2,3,4,1},
            {4,1,2,3}
        };
        REQUIRE(val.isSudokuSolved(full) == true);
    }
}


// =========================
//  TESTS RENDERER
// =========================

TEST_CASE("Renderer – základní vykreslení", "[renderer]") {

    Board board;
    board.setBoardSize(FOUR);
    board.createBoard();

    Renderer renderer;

    SECTION("Renderer nepadá při vykreslení prázdné desky") {
        REQUIRE_NOTHROW(renderer.render(board, 0, 0));
    }

    SECTION("Renderer zvýrazní kurzor") {
        REQUIRE_NOTHROW(renderer.render(board, 2, 3));
    }
}
