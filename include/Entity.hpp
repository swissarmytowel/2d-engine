#pragma once

#include <vector>

#include "utilities.hpp"
#include "Point2D.hpp"
#include "Renderable.hpp"

namespace actor
{
    enum class EntityState
    {
        MOVING = 0,
        STANDING = 1,
        DEAD = 2
    };

    enum class MovementDirection
    {
        UP = 0,
        DOWN = 1,
        RIGHT = 2,
        LEFT = 3
    };

    class Entity: public graphics::Renderable
    {
    public:
        Entity(const Entity &) = default;
        Entity &operator=(const Entity &) = default;

        Entity()
            : _position(util::Point2D()), _state(EntityState::STANDING)
        {};

        explicit Entity(const util::Point2D &position, const std::shared_ptr<graphics::SpriteSheet> &spriteSheet)
            : _position(position), _state(EntityState::STANDING), graphics::Renderable(spriteSheet)
        {};

        virtual void move(const util::Point2D &modifier) = 0;

    private:
        util::Point2D _position;
        EntityState _state;
    };

    using sEntity = std::shared_ptr<Entity>;
    using uEntity = std::unique_ptr<Entity>;
}