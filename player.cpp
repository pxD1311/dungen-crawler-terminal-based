#include "game.hpp"
Player::Player(Position init_position, Stats stats)
    : position(new Position(init_position)), stats(new Stats(stats)) {}
Player::~Player()
{
    delete position;
    delete stats;
}
void Player::setPos(size_t x, size_t y)
{
    position->x = x;
    position->y = y;
}
Position Player::getPos()
{
    return Position(*position);
}

void Player::init(Position pos, Stats sts)
{
    position = new Position(pos);
    stats = new Stats(sts);
}

bool Player::moveUp()
{
    if (position->y > 0)
    {
        position->y--;
        return true;
    }
    return false;
}
bool Player::moveDn()
{
    if (position->y < DUNGEN_SIZE - 1)
    {
        position->y++;
        return true;
    }
    return false;
}
bool Player::moveLt()
{
    if (position->x > 0)
    {
        position->x--;
        return true;
    }
    return false;
}
bool Player::moveRt()
{
    if (position->x < DUNGEN_SIZE - 1)
    {
        position->x--;
        return true;
    }
    return false;
}