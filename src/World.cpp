#include "World.hpp"

void world::World::render(util::uRenderer renderer)
{

}

world::World::World(std::size_t layers,
                    std::size_t worldWidth,
                    std::size_t worldHeight,
                    const std::shared_ptr<graphics::SpriteSheet> &spriteSheet)
    : _layers(layers), _worldWidth(worldWidth), _worldHeight(worldHeight), graphics::Renderable(spriteSheet)
{

}
void world::World::generateRandomLayer(size_t layer)
{

}
