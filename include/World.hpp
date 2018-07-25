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
        World(std::size_t layers,
              std::size_t worldWidth,
              std::size_t worldHeight,
              const std::vector<std::pair<std::size_t, std::size_t>> &spriteBounds,
              const std::shared_ptr<graphics::SpriteSheet> &spriteSheet)
            : _layers(layers), _worldWidth(worldWidth), _worldHeight(worldHeight), graphics::Renderable(spriteSheet)
        {
            _worldMapIds.resize(_layers);

            for(auto i = 0; i < _layers; ++i)
            {
                _worldMapIds[i] = formLayer();
                _worldMapIds[i].generateRandomLayer(spriteBounds[i].first, spriteBounds[i].second);
            }
        }

        void render(util::uRenderer renderer, util::rectangle *dstrect) override
        {
            for(auto &&layer : _worldMapIds)
            {
                for(auto &&i : layer.getLayer())
                {
                    for(auto &&j : i)
                    {

                        //SDL_RenderCopy(renderer.get(), _spriteSheet->getSpriteSheet().get(), _spriteSheet->getSpriteBBoxAt(i) )
                    }
                }
            }
        };

    private:
        world::WorldLayer formLayer()
        {
            static bool tmpId = true;
            if(tmpId)
            {
                return world::WorldLayer(_worldWidth, _worldHeight, 1.0);
            }
            return world::WorldLayer(_worldWidth, _worldHeight, 1.0, world::LayerType::OTHER);
        };

        std::vector<WorldLayer<T>> _worldMapIds;
        std::size_t _layers;
        std::size_t _worldWidth;
        std::size_t _worldHeight;
    };
}