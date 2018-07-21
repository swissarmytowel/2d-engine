#include "Game.hpp"

Uint32 game::Game::WINDOW_FLAGS = SDL_WINDOW_SHOWN;
Uint32 game::Game::RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

void game::Game::update()
{

}

void game::Game::render()
{

}

game::Game::Game()
{
    _window = util::uWindow(SDL_CreateWindow("WINDOW",
                                             SDL_WINDOWPOS_UNDEFINED,
                                             SDL_WINDOWPOS_UNDEFINED,
                                             256,
                                             256,
                                             game::Game::WINDOW_FLAGS));
    _renderer = util::uRenderer(SDL_CreateRenderer(_window.get(), -1, game::Game::RENDERER_FLAGS));

    std::map<std::string, std::pair<std::size_t, std::size_t>> tmp = {{"world.png", {64, 64}}};
    _assetsManager = graphics::AssetsManager(tmp, _renderer);
}

