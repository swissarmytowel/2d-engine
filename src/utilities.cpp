#include "../include/utilities.hpp"

int ::util::initializeSdlSystems(Uint32 sdlFlags, Uint32 imageFlags)
{
    auto sdlErrorCode = SDL_Init(sdlFlags);
    if (sdlErrorCode < 0)
    {
        std::cerr << "SDL cannot be initialized! Exiting with error: " << SDL_GetError();
        return -1;
    }
    auto imgErrorCode = IMG_Init(imageFlags);
    if (imgErrorCode < 0)
    {
        std::cerr << "SDL_Image cannot be initialized! Exiting with error: " << IMG_GetError();
        return -1;
    }
}

void ::util::quitSdlSystems()
{
    IMG_Quit();
    SDL_Quit;
}

util::uTexture util::loadTexture(util::uRenderer &r, const std::string &path)
{
    uTexture tmp(IMG_LoadTexture(r.get(), path.c_str()));
    if (tmp == nullptr) std::cerr << "Cannot load texture " << path << std::endl;
    return tmp;
}
