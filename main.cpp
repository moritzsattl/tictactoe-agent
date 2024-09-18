#include <iostream>
#include <limits>
#include <memory>

#include "src/Board.h"


int main()
{
    auto game = std::make_unique<Board>();

    while (!game->isGameOver())
    {
        int row, col;
        game->showBoard();
        std::cout << "Player " << game->getPlayerOnTurn() << " moves. " << "Enter row (0-2) and column (0-2): ";
        // Input validation loop
        while (!(std::cin >> row >> col) || !game->isMovePossible(row, col)) {
            std::cout << "Invalid input! Please enter two numbers between 0 and 2. Only cells with '-' are valid fields.\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
            game->showBoard();
            std::cout << "Enter row (0-2) and column (0-2): ";
        }

        game = game->makeMove(row, col);
    }
    game->showBoard();
    if (const int winner = game->determineWinner(); winner != -1)
        std::cout << "Player " << winner << " wins. " << '\n';
    else
        std::cout << "There is no winner." << '\n';

    return 0;
}

