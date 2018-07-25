#include <tb_engine.hpp>
#include <debug_utilities.hpp>

void test();
using wLayer = world::WorldLayer<short>;

int main(int argc, char *argv[])
{
    auto error = util::initializeSdlSystems(SDL_INIT_EVERYTHING, IMG_INIT_PNG | IMG_INIT_JPG);
    if (error < 0) return EXIT_FAILURE;

    const int WORLD_WIDTH = 8;
    const int WORLD_HEIGHT = 4;
    const Uint32 WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    const Uint32 RENDERER_FLAGS = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;

    const double FRAME_RATE = 60.0;

    const Uint32 WINDOW_WIDTH = 64*8;
    const Uint32 WINDOW_HEIGHT = 64*4;

    const Uint32 SPRITE_SIZE = 64;

    util::uWindow window(SDL_CreateWindow("WINDOW",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          WINDOW_FLAGS));
    util::uRenderer renderer(SDL_CreateRenderer(window.get(), -1, RENDERER_FLAGS));



    std::map<std::string, std::pair<std::size_t, std::size_t>> tmp = {{"world1.png", {SPRITE_SIZE, SPRITE_SIZE}}};
    graphics::AssetsManager manager(tmp, renderer);

    wLayer ground = wLayer(WORLD_HEIGHT, WORLD_WIDTH, 1, 1.0, 0);
    wLayer sky = wLayer(WORLD_HEIGHT, WORLD_WIDTH, 3, 2.0, 0);

    ground.generateRandomLayer(0, 5);
    sky.generateRandomLayer(6, 12);

    world::World<short> world({ground, sky}, manager.getAsset("world1.png"));

    SDL_Event event{};
    int i = 0;

    while (event.type != SDL_QUIT)
    {
        util::Timer::instance().tick();
        if (util::Timer::instance().getDeltaTime() >= 1.0 / FRAME_RATE)
        {
            util::Timer::instance().reset();

            SDL_RenderClear(renderer.get());
            SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);

            world.render(renderer);

            SDL_RenderPresent(renderer.get());
            SDL_PollEvent(&event);
        }
    }
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