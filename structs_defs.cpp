#include "game.hpp"

// struct Position
Position::Position(size_t x, size_t y)
    : x(x), y(y) {}
Position::Position(const Position &position)
    : x(position.x), y(position.y) {}
bool Position::operator==(Position &rvalue)
{
    return x == rvalue.x && y == rvalue.y;
}

// struct Stats
Stats::Stats(size_t hp, size_t score)
    : hp(hp), score(score) {}
Stats::Stats(const Stats &stats)
    : hp(stats.hp), score(stats.score) {}

// struct DungeonRoom
DungeonRoom::DungeonRoom(ROOM type, bool is_revealed, bool is_wall)
    : type(type), is_revealed(is_revealed), is_wall(is_wall) {}
DungeonRoom::DungeonRoom(const DungeonRoom &dungeonroom)
    : type(dungeonroom.type), is_revealed(dungeonroom.is_revealed), is_wall(dungeonroom.is_wall) {}

std::ostream &operator<<(std::ostream &os, const DungeonRoom &room)
{
    os << " (" << room.type << ") ";
    return os;
}