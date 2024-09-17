#include <iostream>

#include "board.h"

int main()
{
    // TODO: Add game over condition
    // TODO: Overwriting marked piece not possible

    int playerOnTurn = 0;
    auto game = new Board({}, playerOnTurn);

    while (!game->isGameOver())
    {
        int row, col;
        game->showBoard();
        std::cout << "Player " << game->getPlayerOnTurn() << " moves. " << "Enter row (0-2) and column (0-2): ";
        std::cin >> row >> col;
        if(row > 2 || row < 0 || col > 2 || col < 0)
        {
            std::cout << "Invalid input! Please enter a number between 0 and 2.\n";
            continue;
        }
        game = game->makeMove(row, col);
    }

    return 0;
}
