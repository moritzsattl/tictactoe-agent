//
// Created by moritz on 9/18/24.
//

#ifndef AGENT_H
#define AGENT_H
#include <memory>

#include "Board.h"


class Agent {
    private:
        int agentId;
    public:
        explicit Agent(const int agent_id)
            : agentId(agent_id)
        {
        }

        [[nodiscard]] int getAgentId() const
        {
            return agentId;
        }

        [[nodiscard]] int minmax(const std::unique_ptr<Board>& currentBoard) const;

        [[nodiscard]] int getNextMove(const std::unique_ptr<Board>& currentBoard) const;
};



#endif //AGENT_H
