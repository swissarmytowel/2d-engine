#pragma once

#include <vector>
#include <algorithm>

#include "utilities.hpp"

namespace graphics
{
    class SpriteSheet
    {
    public:
        SpriteSheet() = delete;
        SpriteSheet(const SpriteSheet &) = delete;
        SpriteSheet &operator=(const SpriteSheet &) = delete;

        ~SpriteSheet() = default;

        SpriteSheet(util::sTexture &spriteSheet, std::size_t spriteWidth, std::size_t spriteHeight);

        const std::size_t getSpriteWidth() const;
        const std::size_t getSpriteHeight() const;

        const util::sTexture getSpriteSheet() const;

        const SDL_Rect * getSpriteBBoxAt(std::size_t position) const;

    private:
        std::vector<SDL_Rect> _spritesBoundaries;
        util::sTexture _spriteSheet;
        std::size_t _spriteWidth;
        std::size_t _spriteHeight;
    };
}