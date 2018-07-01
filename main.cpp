#include <iostream>
#include "include/utilities.hpp"
#include "include/Point2D.hpp"
#include "include/SpriteSheet.hpp"

int main(int argc, char *argv[])
{
    auto error = util::initializeSdlSystems(SDL_INIT_EVERYTHING, IMG_INIT_PNG | IMG_INIT_JPG);
    if(error < 0) return EXIT_FAILURE;

    const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN;
    const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

    util::uWindow window(SDL_CreateWindow("WINDOW",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          300,
                                          300,
                                          WINDOW_FLAGS));
    util::uRenderer renderer(SDL_CreateRenderer(window.get(), -1, RENDERER_FLAGS));
    util::sTexture texture(util::loadTexture(renderer, "1.png"));

    graphics::SpriteSheet s(texture, 64, 64);
    SDL_Event event{};
    std::size_t i = 0;
    while (event.type != SDL_QUIT)
    {
        SDL_RenderClear(renderer.get());
        SDL_RenderCopy(renderer.get(), s.getSpriteSheet().get(), s.getSpriteBBoxAt(i % 12), nullptr);
        SDL_RenderPresent(renderer.get());
        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                i++;
            }
        }
    }

    util::quitSdlSystems();

    return EXIT_SUCCESS;
}