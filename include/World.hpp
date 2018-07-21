#pragma once

#include <vector>
#include "utilities.hpp"
#include "Renderable.hpp"
#include "Timer.hpp"

namespace world
{
    class World: public graphics::Renderable
    {
    public:
        World(std::size_t layers,
              std::size_t worldWidth,
              std::size_t worldHeight,
              const std::shared_ptr<graphics::SpriteSheet> &spriteSheet);

        void render(util::uRenderer renderer) override;

    private:
        void generateRandomLayer(std::size_t layerId);

        std::vector<std::vector<std::vector<uint32_t>>> _worldMapIds;
        std::size_t _layers;
        std::size_t _worldWidth;
        std::size_t _worldHeight;
    };
}