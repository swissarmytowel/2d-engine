#pragma once
#include <vector>
#include <memory>
#include <string>

#include "utilities.hpp"
#include "Entity.hpp"

namespace game
{
    enum class GameStateType
    {
        PAUSED = 0,
        RUNNING = 1,
        FINISHED = 3
    };

    class Game
    {
    public:
        explicit Game();
        Game(const Game &) = delete;
        Game(Game &&) = default;
        Game &operator=(const Game &) = delete;
        Game &operator=(Game &&) = default;

        void update();
        void render();

    private:
        bool _isFinished;
        GameStateType _stateType;
    };
}