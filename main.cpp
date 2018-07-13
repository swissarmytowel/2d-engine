#include <iostream>
#include "include/utilities.hpp"
#include "include/Point2D.hpp"
#include "include/SpriteSheet.hpp"
#include "include/AssetsManager.hpp"

int main(int argc, char *argv[])
{
    auto error = util::initializeSdlSystems(SDL_INIT_EVERYTHING, IMG_INIT_PNG | IMG_INIT_JPG);
    if (error < 0) return EXIT_FAILURE;

    const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN;
    const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

    util::uWindow window(SDL_CreateWindow("WINDOW",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          256,
                                          256,
                                          WINDOW_FLAGS));
    util::uRenderer renderer(SDL_CreateRenderer(window.get(), -1, RENDERER_FLAGS));

    std::map<std::string, std::pair<std::size_t, std::size_t>> tmp = {{"world.png", {64, 64}}};
    graphics::AssetsManager manager(tmp, renderer);
    SDL_Event event{};
    long i = 0;

    while (event.type != SDL_QUIT)
    {
        SDL_RenderClear(renderer.get());
        SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);

        auto realSpriteSizeInPixels =
            manager.getAsset("world.png").getSpriteSheetSize() * manager.getAsset("world.png").getSpriteWidth();

        auto currentXPositionBackground = -i;
        auto currentXPositionBufferedBackground = realSpriteSizeInPixels - i;

        SDL_Rect current = {currentXPositionBackground, 0, realSpriteSizeInPixels, realSpriteSizeInPixels};
        SDL_Rect next = {currentXPositionBufferedBackground, 0, realSpriteSizeInPixels, realSpriteSizeInPixels};

        SDL_RenderCopy(renderer.get(), manager.getAsset("world.png").getSpriteSheet().get(), nullptr, &current);
        SDL_RenderCopy(renderer.get(), manager.getAsset("world.png").getSpriteSheet().get(), nullptr, &next);

        SDL_RenderPresent(renderer.get());
        SDL_PollEvent(&event);

        i += i < realSpriteSizeInPixels - 6 ? 5 : -i;
    }

    util::quitSdlSystems();

    return EXIT_SUCCESS;
}