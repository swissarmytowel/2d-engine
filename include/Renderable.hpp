#pragma once

#include "utilities.hpp"
#include "SpriteSheet.hpp"

class Renderable
{
public:
    Renderable() = default;
    Renderable(const Renderable &) = default;
    Renderable &operator=(const Renderable &) = default;

    virtual void render() = 0;

    ~Renderable() = default;

private:
    std::shared_ptr<graphics::SpriteSheet> _spriteSheet;
};