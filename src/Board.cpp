//
// Created by moritz on 9/16/24.
//

#include "Board.h"

#include <iostream>
#include <algorithm>
#include <memory>

Board::Board() :
    state({'-','-','-','-','-','-','-','-','-'})
{
}

Board::Board(const std::pair<short, short>& last_move, const std::array<char, 9>& state) :
    lastMove(last_move),
    state(state)
{
}


std::unique_ptr<Board> Board::makeMove(const int row, const int col) const
{
    auto nextState = this->state;
    nextState[(row * 3) + col] = getPlayerCharFromId(this->getPlayerOnTurn());

    return std::make_unique<Board>(std::pair<short, short>(row, col), nextState);
}

bool Board::isMovePossible(const int row, const int col) const
{
    if(row < 0 || row > 2 || col < 0 || col > 2) return false;

    if(this->state[(row * 3) + col] != '-') return false;

    return true;
}

std::array<bool, 9> Board::getPossibleMoves() const
{
    std::array<bool, 9> possibleMoves = {};
    for(int i = 0; i < 9; i++)
    {
        possibleMoves[i] = this->state[i] == '-';
    }
    return possibleMoves;
}

int Board::determineWinner() const
{
    const int lastPlayerId = (this->getPlayerOnTurn() + 1) % 2;
    const char lastPlayerChar = getPlayerCharFromId(lastPlayerId);
    const short lastMoveRow = this->lastMove.first;
    const short lastMoveCol = this->lastMove.second;

    // Check row
    if(this->state[lastMoveRow * 3] == lastPlayerChar &&
        this->state[lastMoveRow * 3 + 1] == lastPlayerChar &&
        this->state[lastMoveRow * 3 + 2] == lastPlayerChar) return lastPlayerId;

    // Check col
    if(this->state[0 * 3 + lastMoveCol] == lastPlayerChar &&
        this->state[1 * 3 + lastMoveCol] == lastPlayerChar &&
        this->state[2 * 3 + lastMoveCol] == lastPlayerChar) return lastPlayerId;

    // Check diag
    if(lastMoveRow == lastMoveCol)
    {
        if (this->state[0 * 3 + 0] == lastPlayerChar &&
            this->state[1 * 3 + 1] == lastPlayerChar &&
            this->state[2 * 3 + 2] == lastPlayerChar) return lastPlayerId;
    };

    // Check diag
    if(lastMoveRow + lastMoveCol == 2)
    {
        if (this->state[0 * 3 + 2] == lastPlayerChar &&
            this->state[1 * 3 + 1] == lastPlayerChar &&
            this->state[2 * 3 + 0] == lastPlayerChar) return lastPlayerId;
    };

    return -1;
}

bool Board::isGameOver() const
{
    return std::ranges::find(this->state, '-') == this->state.end() || this->determineWinner() != -1 ;
}

char Board::getPlayerCharFromId(const int playerId)
{
    if(playerId == 0) return 'X';
    if(playerId == 1) return 'O';
    return '-';
}

short Board::getPlayerIdFromChar(const char playerChar)
{
    if(playerChar == 'X') return 0;
    if(playerChar == 'O') return 1;
    return -1;
}

void Board::showBoard() const
{
    std::cout << "*******" << '\n' << "  0 1 2";
    for (auto i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
        {
            std::cout << '\n' << i / 3 << ' ';
        }
        std::cout << this->state[i] << ' ';

    }
    std::cout << '\n' << "*******" << '\n';
}

int Board::getPlayerOnTurn() const
{
    return this->state[(this->lastMove.first * 3) + this->lastMove.second] == 'X' ? 1 : 0;
}