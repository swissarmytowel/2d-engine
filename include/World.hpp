#pragma once

#include <vector>
#include "utilities.hpp"
#include "Renderable.hpp"
#include "Timer.hpp"
#include "WorldLayer.hpp"
#include <debug_utilities.hpp>

namespace world
{
    template<typename T>
    class World: public graphics::Renderable
    {
    public:
        World(const std::vector<world::WorldLayer<T>> &layers, const std::shared_ptr<graphics::SpriteSheet> &sprites)
            : _layers(layers), Renderable(sprites)
        {}

        const std::vector<world::WorldLayer<T>> &getLayers() const
        {
            return _layers;
        }

        void render(util::uRenderer &renderer) override
        {
            for (auto layer = 0; layer < _layers.size(); ++layer)
            {
                util::rectangle currentTileRenderPosition = {0, _spriteSheet->getSpriteHeight() * layer, _spriteSheet
                    ->getSpriteWidth(), _spriteSheet->getSpriteHeight()};
                for (auto i = 0; i < _layers[layer].getLayer().size(); ++i)
                {
                    for (auto &&j : _layers[layer].getLayer()[i])
                    {
                        if (j != -1)
                        {
                            SDL_RenderCopy(renderer.get(),
                                           _spriteSheet->getSpriteSheet().get(),
                                           _spriteSheet->getSpriteBBoxAt(j),
                                           &currentTileRenderPosition);
                            currentTileRenderPosition.x += _spriteSheet->getSpriteWidth();
                        }
                    }
                    currentTileRenderPosition.x = 0;
                    currentTileRenderPosition.y += _spriteSheet->getSpriteHeight();
                }
            }
        }

    private:
        std::vector<world::WorldLayer<T>> _layers;
    };
}