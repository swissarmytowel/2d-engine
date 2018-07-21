#pragma once
#include <vector>
#include <memory>
#include <string>

#include "utilities.hpp"
#include "Point2D.hpp"
#include "AssetsManager.hpp"
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
        Game();
        Game(const Game &) = delete;
        Game &operator=(const Game &) = delete;

        void update();
        void render();

        static Uint32 WINDOW_FLAGS;
        static Uint32 RENDERER_FLAGS;

    private:
        bool _isFinished;
        GameStateType _stateType;

        graphics::AssetsManager _assetsManager;
        std::vector<actor::sEntity> _entities;

        util::uWindow _window;
        util::uRenderer _renderer;
    };
}