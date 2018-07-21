#include "../include/AssetsManager.hpp"

graphics::AssetsManager::AssetsManager(const std::map<std::string,
                                                      std::pair<std::size_t, std::size_t>> &filenamesAndTileSizes,
                                       util::uRenderer &renderer)
{
    for (auto &&filename : filenamesAndTileSizes)
    {
        util::uTexture texture (util::loadTexture(renderer, filename.first));
        _spriteSheets.insert(std::make_pair(filename.first, std::make_shared<graphics::SpriteSheet>(texture,
                                                                                  filename.second.first,
                                                                                  filename.second.second)));
    }
}

const std::shared_ptr<graphics::SpriteSheet> graphics::AssetsManager::getAsset(const std::string &name)
{
    return _spriteSheets[name];
}
