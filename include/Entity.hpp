#pragma once

#include "Point2D.hpp"

namespace actor
{
    class Entity
    {
    public:
        ~Entity() = default;
        Entity(const Entity &) = default;
        Entity &operator=(const Entity &) = default;

        Entity(): _position(util::Point2D()) {};
        explicit Entity(const util::Point2D &position)
            : _position(position)
        {};

        virtual void move(const util::Point2D &modifier) = 0;

    private:
        util::Point2D _position;
    };
}