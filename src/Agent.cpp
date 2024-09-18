//
// Created by moritz on 9/18/24.
//

#include "Agent.h"


int Agent::minmax(const std::unique_ptr<Board>& currentBoard) const
{
    if(currentBoard->isGameOver())
    {
        const auto winner = currentBoard->determineWinner();
        if(winner == this->agentId) return 1;
        if(winner == -1) return 0;

        // In this case enemy has won
        return -1;
    }

    const auto possibleMoves = currentBoard->getPossibleMoves();
    const int playerOnTurn = currentBoard->getPlayerOnTurn();
    int bestScore = playerOnTurn == this->agentId ? -2 : 2;
    for (int i = 0; i < 9; i++)
    {
        if(!possibleMoves[i]) continue;
        const auto score = minmax(currentBoard->makeMove(i / 3, i % 3));

        // Agents turn -> maximize score
        if ( playerOnTurn == this->agentId && score > bestScore)
        {
            bestScore = score;
        }

        // Enemies turn -> minimize agents score
        if( playerOnTurn != this->agentId && score < bestScore)
        {
            bestScore = score;
        }

    }
    return bestScore;

}

int Agent::getNextMove(const std::unique_ptr<Board>& currentBoard) const
{
    const auto possibleMoves = currentBoard->getPossibleMoves();
    int move = -1;
    int bestScore = -2;

    for (int i = 0; i < 9; i++)
    {
        if(!possibleMoves[i]) continue;

        if(const auto score = minmax(currentBoard->makeMove(i / 3, i % 3)); score > bestScore)
        {
            bestScore = score;
            move = i;
        }

    }
    return move;

}

