//
// Created by moritz on 9/16/24.
//

#include "board.h"

#include <iostream>

Board::Board(const std::array<char, 9>& state, const int playerOnTurn) :
    state {state},
    playerOnTurn {playerOnTurn}
{
}

Board* Board::makeMove(const int row, const int col) const
{
    auto nextState = this->state;
    nextState[(row * 3) + col] = this->playerOnTurn == 0 ? 'X' : 'O';

    return new Board(nextState, (playerOnTurn + 1) % 2);
}

bool Board::isGameOver()
{
    return false;
}

void Board::showBoard() const
{
    std::cout << "---";
    for (auto i = 0; i < 9; i++)
    {
        if(i % 3 == 0) std::cout << '\n';
        std::cout << this->state[i];
    }
    std::cout << '\n' << "---" << '\n';
}

int Board::getPlayerOnTurn() const
{
    return this->playerOnTurn;
}
