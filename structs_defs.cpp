#include "game.hpp"

// struct Position
Position::Position(size_t x, size_t y)
    : x(x), y(y) {}
Position::Position(const Position &position)
    : x(position.x), y(position.y) {}

// struct Stats
Stats::Stats(size_t hp, size_t score)
    : hp(hp), score(score) {}
Stats::Stats(const Stats &stats)
    : hp(stats.hp), score(stats.score) {}

// struct DungeonRoom
DungenRoom::DungenRoom(Room type, bool is_revealed, bool is_wall)
    : type(type), is_revealed(is_revealed), is_wall(is_wall) {}
DungenRoom::DungenRoom(const DungenRoom &dungeonroom)
    : type(dungeonroom.type), is_revealed(dungeonroom.is_revealed), is_wall(dungeonroom.is_wall) {}