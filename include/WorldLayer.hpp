#pragma once

#include <vector>
#include <random>
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
        WorldLayer(std::size_t width, std::size_t height, double speed, LayerType type=LayerType::GROUND)
            : _width(width), _height(height), _speed(speed), _type(type)
        {
            _layer.resize(_height);
            for(auto &&item : _layer)
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
            for(auto &&i : _layer)
            {
                for(auto &&ii : i)
                {
                    ii = static_cast<T>(std::rand() % upperId + lowerId);
                }
            }
        }

    private:
        std::vector<std::vector<T>> _layer;
        std::size_t _width;
        std::size_t _height;
        double _speed;
        LayerType _type;
    };
}