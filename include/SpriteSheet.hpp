#pragma once

#include <vector>
#include <algorithm>

#include "utilities.hpp"

namespace graphics
{
    class SpriteSheet
    {
    public:
        SpriteSheet() = default;
        SpriteSheet(SpriteSheet &&) = default;
        SpriteSheet &operator=(SpriteSheet &&) = default;

        ~SpriteSheet() = default;

        SpriteSheet(util::uTexture &spriteSheet, std::size_t spriteWidth, std::size_t spriteHeight);

        const std::size_t getSpriteWidth() const;
        const std::size_t getSpriteHeight() const;

        const util::uTexture &getSpriteSheet() const;

        const SDL_Rect * getSpriteBBoxAt(std::size_t position) const;
        const std::size_t getSpriteSheetSize() const;

        util::uTexture &formTile(util::uRenderer renderer, const std::vector<std::size_t> &positions, std::size_t width, std::size_t height);

    private:
        std::vector<SDL_Rect> _spritesBoundaries;
        util::uTexture _spriteSheet;
        std::size_t _spriteWidth;
        std::size_t _spriteHeight;
        std::size_t _spriteSheetSize;
    };
}