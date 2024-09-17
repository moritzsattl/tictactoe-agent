//
// Created by moritz on 9/16/24.
//
#include <array>

#ifndef BOARD_H
#define BOARD_H

class Board
{
    private:
        const std::array<char, 9> state;
        const int playerOnTurn;
    public:
        Board(const std::array<char, 9>& state, int playerOnTurn);


        [[nodiscard]] Board* makeMove(int row, int col) const;

        static bool isGameOver();

        void showBoard() const;

        [[nodiscard]] int getPlayerOnTurn() const;
};



#endif //BOARD_H
