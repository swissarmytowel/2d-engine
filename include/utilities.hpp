#pragma once

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace util
{
    // SDL deleter helper class
    class SdlDeleter
    {
    public:
        void operator()(SDL_Texture *texture)
        {
            if (texture) SDL_DestroyTexture(texture);
        }

        void operator()(SDL_Window *window)
        {
            if (window) SDL_DestroyWindow(window);
        }

        void operator()(SDL_Renderer *renderer)
        {
            if (renderer) SDL_DestroyRenderer(renderer);
        }
    };

    // Shared ptr with deleter class
    template<class T, class D = std::default_delete<T>>
    class SharedPtr: public std::shared_ptr<T>
    {
    public:
        explicit SharedPtr(T *pointer = nullptr)
            : std::shared_ptr<T>(pointer, D())
        {}
        // Hides and 'overrides' non-virtual function from std::shared_ptr
        void reset(T *pointer = nullptr)
        {
            std::shared_ptr<T>::reset(pointer, D());
        }
    };

    // Unique pointers to SDL main types
    using uTexture = std::unique_ptr<SDL_Texture, SdlDeleter>;
    using uWindow = std::unique_ptr<SDL_Window, SdlDeleter>;
    using uRenderer = std::unique_ptr<SDL_Renderer, SdlDeleter>;

    // Shared pointers to SDL main types
    using sTexture = SharedPtr<SDL_Texture, SdlDeleter>;
    using sWindow = SharedPtr<SDL_Window, SdlDeleter>;
    using sRenderer = SharedPtr<SDL_Renderer, SdlDeleter>;

    // Initializer and deinitializer functions for SDL
    int initializeSdlSystems(Uint32 sdlFlags, Uint32 imageFlags);;

    void quitSdlSystems();

    sTexture loadTexture(uRenderer &r, const std::string &path);
}