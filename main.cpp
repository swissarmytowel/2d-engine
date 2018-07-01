#include <iostream>
#include "include/utilities.hpp"
#include "include/Point2D.hpp"

int main(int argc, char *argv[])
{
    auto error = util::initializeSdlSystems(SDL_INIT_EVERYTHING, IMG_INIT_PNG | IMG_INIT_JPG);
    if(error < 0) return EXIT_FAILURE;

    const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN;
    const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

    util::uWindow window(SDL_CreateWindow("WINDOW",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          100,
                                          100,
                                          WINDOW_FLAGS));
    util::uRenderer renderer(SDL_CreateRenderer(window.get(), -1, RENDERER_FLAGS));
    util::uTexture texture( util::loadTexture(renderer, "29.jpg"));
    util::uTexture texture1( util::loadTexture(renderer, "55.jpg"));

    SDL_Event event{};
    std::size_t counter = 0;

    while (event.type != SDL_QUIT)
    {
        SDL_RenderClear(renderer.get());
        SDL_RenderCopy(renderer.get(), counter % 10 == 0 ? texture.get(): texture1.get(), nullptr, nullptr);
        SDL_RenderPresent(renderer.get());

        SDL_PollEvent(&event);
        counter++;
    }

    util::quitSdlSystems();

    return EXIT_SUCCESS;
}