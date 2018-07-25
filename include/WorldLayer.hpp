#pragma once

#include <vector>
#include <random>
#include <ctime>
#include "utilities.hpp"

namespace world
{
    enum class LayerType
    {
        GROUND = 0,
        OTHER = 1
    };

    template<typename T>
    class WorldLayer
    {
    public:
        WorldLayer() = default;
        WorldLayer(std::size_t worldHeight,
                   std::size_t layerWidth,
                   std::size_t layerHeight,
                   double speed,
                   LayerType type = LayerType::GROUND)
            : _width(layerWidth), _height(layerHeight), _speed(speed), _type(type)
        {
            _layer.resize(worldHeight);
            for (auto &&item : _layer)
            {
                item.resize(_width);
            }
        }

        std::vector<std::vector<T>> getLayer()
        {
            return _layer;
        }

        void generateRandomLayer(std::size_t lowerId, std::size_t upperId)
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            for (auto i = 0; i < _layer.size(); ++i)
            {
                for (auto &&ii : _layer[i])
                {
                    if (i > _layer.size() - _height - 1)
                        ii = static_cast<T>(std::rand() % upperId + lowerId);
                    else
                        ii = static_cast<T>(-1);
                }
            }
        }

    private:
        std::vector<std::vector<T>> _layer;
        std::size_t _width;
        std::size_t _height;
        std::size_t _worldHeight;
        double _speed;
        LayerType _type;
    };
}