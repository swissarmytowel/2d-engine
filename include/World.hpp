#pragma once

#include <vector>
#include "utilities.hpp"
#include "Renderable.hpp"
#include "Timer.hpp"
#include "WorldLayer.hpp"

namespace world
{
    template<typename T>
    class World: public graphics::Renderable
    {
    public:
        World(const std::vector<world::WorldLayer<T>> &layers, const std::shared_ptr<graphics::SpriteSheet> &sprites)
            : _layers(layers), _sprites(sprites)
        {

        }

        const std::vector<world::WorldLayer<T>> &getLayers() const
        {
            return _layers;
        }

        const std::shared_ptr<graphics::SpriteSheet> &getSprites() const
        {
            return _sprites;
        }

        void render(util::uRenderer renderer) override
        {
            
        }

    private:
        std::vector<world::WorldLayer<T>> _layers;
        std::shared_ptr<graphics::SpriteSheet> _sprites;
    };
}