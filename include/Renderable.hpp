#pragma once

#include "utilities.hpp"
#include "SpriteSheet.hpp"

namespace graphics
{
    class Renderable
    {
    public:
        Renderable() = default;
        Renderable(const Renderable &) = default;
        Renderable &operator=(const Renderable &) = default;
        Renderable(const std::shared_ptr<graphics::SpriteSheet> &spriteSheet)
            : _spriteSheet(spriteSheet)
        {}

        virtual void render(util::uRenderer renderer, util::rectangle *dstrect) = 0;

        virtual ~Renderable() = default;

    protected:
        std::shared_ptr<graphics::SpriteSheet> _spriteSheet;
    };
}