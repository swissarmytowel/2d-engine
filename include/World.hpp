#pragma once

#include <vector>
#include "utilities.hpp"
#include "AssetsManager.hpp"
#include "Timer.hpp"

namespace world
{
    class World
    {
    public:
        World(std::size_t layers, std::size_t worldWidth, std::size_t worldHeight);
    private:
        std::vector<std::vector<std::vector<uint32_t>>> _worldMapIds;
        std::size_t _layers;
        std::size_t _world;
    };
}