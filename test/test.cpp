#include "Board.h"
#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("Board - Determine Winner", "[board]") {
    SECTION("Horizontal win conditions") {
        // Top row horizontal win
        auto board1 = std::make_unique<Board>(std::make_pair(0, 2), std::array<char, 9>{'X', 'X', 'X', '-', '-', '-', '-', '-', '-'});
        REQUIRE(board1->determineWinner() == 0);

        // Middle row horizontal win
        auto board2 = std::make_unique<Board>(std::make_pair(1, 2), std::array<char, 9>{'-', '-', '-', 'O', 'O', 'O', '-', '-', '-'});
        REQUIRE(board2->determineWinner() == 1);

        // Bottom row horizontal win
        auto board3 = std::make_unique<Board>(std::make_pair(2, 2), std::array<char, 9>{'-', '-', '-', '-', '-', '-', 'X', 'X', 'X'});
        REQUIRE(board3->determineWinner() == 0);
    }

    SECTION("Vertical win conditions") {
        // Left column vertical win
        auto board1 = std::make_unique<Board>(std::make_pair(2, 0), std::array<char, 9>{'O', '-', '-', 'O', '-', '-', 'O', '-', '-'});
        REQUIRE(board1->determineWinner() == 1);

        // Middle column vertical win
        auto board2 = std::make_unique<Board>(std::make_pair(2, 1), std::array<char, 9>{'-', 'X', '-', '-', 'X', '-', '-', 'X', '-'});
        REQUIRE(board2->determineWinner() == 0);

        // Middle column 2 vertical win
        auto board3 = std::make_unique<Board>(std::make_pair(2, 1), std::array<char, 9>{'X', 'X', 'O', 'O', 'X', '-', 'O', 'X', '-'});
        REQUIRE(board3->determineWinner() == 0);

        // Right column vertical win
        auto board4 = std::make_unique<Board>(std::make_pair(2, 2), std::array<char, 9>{'-', '-', 'O', '-', '-', 'O', '-', '-', 'O'});
        REQUIRE(board4->determineWinner() == 1);
    }

    SECTION("Diagonal win conditions") {
        // Top-left to bottom-right diagonal win
        auto board1 = std::make_unique<Board>(std::make_pair(2, 2), std::array<char, 9>{'X', '-', '-', '-', 'X', '-', '-', '-', 'X'});
        REQUIRE(board1->determineWinner() == 0);

        // Top-right to bottom-left diagonal win
        auto board2 = std::make_unique<Board>(std::make_pair(2, 0), std::array<char, 9>{'-', '-', 'O', '-', 'O', '-', 'O', '-', '-'});
        REQUIRE(board2->determineWinner() == 1);
    }

    SECTION("No winner - Incomplete board") {
        // No winner on the board yet
        auto board = std::make_unique<Board>(std::make_pair(0, 1), std::array<char, 9>{'X', 'O', '-', '-', '-', '-', '-', '-', '-'});
        REQUIRE(board->determineWinner() == -1);
    }

    SECTION("No winner - Full board (tie)") {
        // Full board with no winner (tie)
        auto board = std::make_unique<Board>(std::make_pair(2, 2), std::array<char, 9>{'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'O'});
        REQUIRE(board->determineWinner() == -1);
    }

    SECTION("Edge case - One move made") {
        // Only one move has been made
        auto board = std::make_unique<Board>(std::make_pair(0, 0), std::array<char, 9>{'X', '-', '-', '-', '-', '-', '-', '-', '-'});
        REQUIRE(board->determineWinner() == -1);
    }

    SECTION("Edge case - Empty board") {
        // No moves have been made
        auto board = std::make_unique<Board>();
        REQUIRE(board->determineWinner() == -1);
    }
}
