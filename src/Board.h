//
// Created by moritz on 9/16/24.
//
#include <array>
#include <memory>

#ifndef BOARD_H
#define BOARD_H

class Board
{
    private:
        /**
         * Keeps track of last move.
         * First element of pair maps to row.
         * Second element of pair maps to col.
         */
        const std::pair<short, short> lastMove;

        /**
         * Holds the state of the game
         */
        const std::array<char, 9> state;
    public:
        Board();

        Board(const std::pair<short, short>& last_move, const std::array<char, 9>& state);

        /**
         * Makes a move for the current player
         * @param row
         * @param col
         * @return Returns new Game
         */
        [[nodiscard]] std::unique_ptr<Board> makeMove(int row, int col) const;

        [[nodiscard]] bool isMovePossible(int row, int col) const;

        /**
         *
         * @return 0 iff player 0 wins, 1 iff player 1 wins, -1 iff draw
         */
        [[nodiscard]] int determineWinner() const;

        [[nodiscard]] bool isGameOver() const;

         /**
         *
         * @param playerId
         * @return the char corresponding to playerId else '-'
         */
        static char getPlayerCharFromId(int playerId);
        static short getPlayerIdFromChar(char playerChar);

        /**
         * Prints the board to stdout
         */
        void showBoard() const;

        /**
         * @return the id of the player who is making the next move
         */
        [[nodiscard]] int getPlayerOnTurn() const;
};



#endif //BOARD_H
