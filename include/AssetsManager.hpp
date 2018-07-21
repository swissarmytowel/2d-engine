#pragma once

#include <map>
#include <string>

#include "utilities.hpp"
#include "SpriteSheet.hpp"

namespace graphics
{
    class AssetsManager
    {
    public:
        AssetsManager() = default;
        AssetsManager(const AssetsManager &) = delete;
        AssetsManager &operator=(AssetsManager &&) = default;

        AssetsManager(const std::map<std::string, std::pair<std::size_t, std::size_t>> &filenamesAndTileSizes,
                      util::uRenderer &renderer);

        const graphics::SpriteSheet &getAsset(const std::string &name);

    private:
        std::map<std::string, graphics::SpriteSheet> _spriteSheets;
    };
}