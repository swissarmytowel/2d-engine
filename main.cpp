#include <iostream>

#include "include/utilities.hpp"
#include "include/Point2D.hpp"
#include "include/SpriteSheet.hpp"
#include "include/AssetsManager.hpp"
#include "include/Timer.hpp"
#include "include/World.hpp"
#include "include/WorldLayer.hpp"

void test();

int main(int argc, char *argv[])
{
    auto error = util::initializeSdlSystems(SDL_INIT_EVERYTHING, IMG_INIT_PNG | IMG_INIT_JPG);
    if (error < 0) return EXIT_FAILURE;

    test();

    util::quitSdlSystems();

    return EXIT_SUCCESS;
}

void test()
{
    const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

    const double FRAME_RATE = 60.0;

    const Uint32 WINDOW_WIDTH = 256*2;
    const Uint32 WINDOW_HEIGHT = 256;

    const Uint32 SPRITE_SIZE = 64;


    util::uWindow window(SDL_CreateWindow("WINDOW",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          WINDOW_FLAGS));
    util::uRenderer renderer(SDL_CreateRenderer(window.get(), -1, RENDERER_FLAGS));

    std::map<std::string, std::pair<std::size_t, std::size_t>> tmp = {{"world.png", {SPRITE_SIZE, SPRITE_SIZE}}};
    graphics::AssetsManager manager(tmp, renderer);
    SDL_Event event{};
    int i = 0;

    auto realSpriteSizeInPixels =
        manager.getAsset("world.png")->getSpriteSheetSize() * manager.getAsset("world.png")->getSpriteWidth();

    while (event.type != SDL_QUIT)
    {
        util::Timer::instance().tick();
        if (util::Timer::instance().getDeltaTime() >= 1.0 / FRAME_RATE)
        {
            util::Timer::instance().reset();

            SDL_RenderClear(renderer.get());
            SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);

            auto currentXPositionBackground = -i;
            auto currentXPositionBufferedBackground = WINDOW_WIDTH - i;

            util::rectangle current = {currentXPositionBackground, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
            util::rectangle
                next = {currentXPositionBufferedBackground, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

            SDL_RenderCopy(renderer.get(), manager.getAsset("world.png")->getSpriteSheet().get(), nullptr, &current);
            SDL_RenderCopy(renderer.get(), manager.getAsset("world.png")->getSpriteSheet().get(), nullptr, &next);

            SDL_RenderPresent(renderer.get());
            SDL_PollEvent(&event);

            i += i < WINDOW_WIDTH - SPRITE_SIZE / 8 ? SPRITE_SIZE / 8 -  SPRITE_SIZE / 16: -i;
        }
    }

}