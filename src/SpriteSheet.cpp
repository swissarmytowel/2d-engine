#include "../include/SpriteSheet.hpp"

graphics::SpriteSheet::SpriteSheet(util::sTexture &spriteSheet, std::size_t spriteWidth, std::size_t spriteHeight)
    : _spriteSheet(std::move(spriteSheet)), _spriteWidth(spriteWidth), _spriteHeight(spriteHeight)
{
    if (_spriteSheet == nullptr)
    {
        std::cerr << "Null texture passed as sprite sheet "<< std::endl;
        return;
    }
    auto spriteSheetWidth = 0;
    auto spriteSheetHeight = 0;

    auto queryError = SDL_QueryTexture(_spriteSheet.get(), nullptr, nullptr, &spriteSheetWidth, &spriteSheetHeight);
    if (queryError < 0)
    {
        std::cerr << "Error occurred while queering texture. Error: " << SDL_GetError() << std::endl;
        return;
    }
    if (spriteSheetHeight == 0 || spriteSheetWidth == 0 || spriteSheetHeight % _spriteHeight != 0
        || spriteSheetWidth % _spriteWidth != 0)
    {
        std::cerr << "Wrong sprite sheet dimensions! Width: " << spriteSheetWidth << " Height: " << spriteSheetHeight
                  << std::endl;
        return;
    }
    auto spritesQuantityHorizontal = (spriteSheetWidth / _spriteWidth);
    auto spritesQuantityVertical = (spriteSheetHeight / _spriteHeight);

    _spritesBoundaries.reserve(spritesQuantityHorizontal * spritesQuantityVertical);
    for (std::size_t i = 0; i < spritesQuantityVertical; ++i)
    {
        for (std::size_t j = 0; j < spritesQuantityHorizontal; ++j)
        {
            _spritesBoundaries[spritesQuantityHorizontal * i + j] =
                {j * _spriteWidth, i * _spriteHeight, _spriteWidth, _spriteHeight};
        }
    }
}

const std::size_t graphics::SpriteSheet::getSpriteWidth() const
{
    return _spriteWidth;
}

const std::size_t graphics::SpriteSheet::getSpriteHeight() const
{
    return _spriteHeight;
}

const SDL_Rect * graphics::SpriteSheet::getSpriteBBoxAt(std::size_t position) const
{
    return &_spritesBoundaries[position];
}

const util::sTexture graphics::SpriteSheet::getSpriteSheet() const
{
    return _spriteSheet;
}
