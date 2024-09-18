#include <iostream>
#include <limits>
#include <memory>

#include "Agent.h"
#include "src/Board.h"


int main()
{
    // TODO only use 0 - 9 for moves made accept row and col from user, but transform it at the beginning
    // TODO only use 'X' and 'O' for player id
    char start;
    std::cout << "Let's play a game of tic tac toe. Do you want to go first? (y/n)? ";
    while (!(std::cin >> start) || start != 'y' && start != 'n')
    {
        std::cout << "Invalid input! Please type 'y' or 'n'.\n";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
    }

    auto game = std::make_unique<Board>();
    const auto agent = std::make_unique<Agent>(start == 'y' ? 1 : 0);
    bool firstMove = start == 'y' ? true : false;

    while (!game->isGameOver())
    {
        int row, col;
        game->showBoard();
        if (game->getPlayerOnTurn() == agent->getAgentId())
        {
            const auto move = agent->getNextMove(game);
            row = move / 3;
            col = move % 3;

            // Say something, if it's not the first move
            if (!firstMove)
            {
                switch (agent->minmax(game->makeMove(row, col)))
                {
                case 1:
                    std::cout << "You're a noob." << std::endl;
                    break;
                case 0:
                    std::cout << "Decent move." << std::endl;
                    break;
                case -1:
                    std::cout << "You play good." << std::endl;
                    break;
                default: ;
                }
            }
            else firstMove = false;


            std::cout << "I put a piece on " << row << " " << col << '.' << std::endl;
        }
        else
        {
            std::cout << "It's your turn. " << "Enter row (0-2) and column (0-2): ";
            // Input validation loop
            while (!(std::cin >> row >> col) || !game->isMovePossible(row, col))
            {
                std::cout <<
                    "Invalid input! Please enter two numbers between 0 and 2. Only cells with '-' are valid fields.\n";
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
                game->showBoard();
                std::cout << "Enter row (0-2) and column (0-2): ";
            }
        }


        game = game->makeMove(row, col);
    }
    game->showBoard();
    if (const int winner = game->determineWinner(); winner != -1)
        if (winner == (start == 'y' ? 1 : 0))
            std::cout << "You lose." << '\n';
        else
            std::cout << "You win." << '\n';
    else
        std::cout << "It's a draw." << '\n';

    return 0;
}
