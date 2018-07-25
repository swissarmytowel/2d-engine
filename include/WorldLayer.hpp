#pragma once

#include <vector>
#include <random>
#include <ctime>
#include "utilities.hpp"

namespace world
{
    template<typename T>
    class WorldLayer
    {
    public:
        WorldLayer() = default;
        WorldLayer(std::size_t worldHeight,
                   std::size_t layerWidth,
                   std::size_t layerHeight,
                   double speed,
                   short id)
            : _width(layerWidth), _height(layerHeight), _speed(speed), _id(id), _worldHeight(worldHeight)
        {
            _layer.resize(_worldHeight);
            for (auto &&item : _layer)
            {
                item.resize(_width, static_cast<T>(-1));
            }
        }

        std::vector<std::vector<T>> getLayer()
        {
            return _layer;
        }

        void generateRandomLayer(std::size_t lowerId, std::size_t upperId)
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(lowerId, upperId); // define the range
            for (auto i = currentHeightLevel; i < _worldHeight; ++i)
            {
                for (auto &&ii : _layer[i])
                {
                    if (i >= _worldHeight - (_height + currentHeightLevel))
                    {
                        ii = distr(eng);
                    }
                }
            }
            currentHeightLevel += _height;
        }

        static std::size_t currentHeightLevel;

    private:
        std::vector<std::vector<T>> _layer;
        std::size_t _width;
        std::size_t _height;
        std::size_t _worldHeight;
        double _speed;
        short _id;
    };

    template<typename T>
    std::size_t world::WorldLayer<T>::currentHeightLevel = 0;
}