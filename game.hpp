#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "utility.hpp"

const size_t MONSTER_DMG = 10;
const size_t TRAP_DMG = 10;
const size_t TREASURE_SCORE = 20;

namespace PLAYER
{
    const size_t INIT_HP = 100;
    const size_t INIT_SCORE = 0;
    const size_t INIT_POS_X = 0;
    const size_t INIT_POS_Y = 0;
}

namespace DUNGEON
{
    const size_t DUNGEON_SIZE = 5;
    const size_t MONSTER_NUM = 3;
    const size_t TREASURE_NUM = 3;
    const size_t TRAP_NUM = 3;
    const size_t EXIT_NUM = 1;
}

enum ROOM
{
    EMPTY,
    MONSTER,
    TREASURE,
    TRAP,
    EXIT
};

struct Position
{
    size_t x, y;
    Position(size_t x = PLAYER::INIT_POS_X, size_t y = PLAYER::INIT_POS_Y);
    Position(const Position &position);
    bool operator==(Position &rvalue);
};

struct Stats
{
    size_t hp, score;
    Stats(size_t hp = PLAYER::INIT_HP, size_t score = PLAYER::INIT_SCORE);
    Stats(const Stats &stats);
};

struct DungeonRoom
{
    ROOM type;
    bool is_revealed;
    bool is_wall;
    DungeonRoom(ROOM type = ROOM::EMPTY, bool is_revealed = false, bool is_wall = false);
    DungeonRoom(const DungeonRoom &dungeonROOM);
};
std::ostream &operator<<(std::ostream &os, const DungeonRoom &ROOM);

class Player
{
private:
    Position *position;
    Stats *stats;

public:
    Player(Position init_position, Stats stats);
    ~Player();
    void setPos(size_t x, size_t y);
    Position getPos();

    void init(Position pos, Stats sts);
    bool moveUp();
    bool moveDn();
    bool moveLt();
    bool moveRt();
};

class Dungeon
{
private:
    size_t size;
    DungeonRoom **rooms;
    Player *player;

public:
    Dungeon(size_t size, Position init_position, Stats stats);
    ~Dungeon();
    void init(Position init_position, Stats stats);
    void display();
    void generate();
};

class Game
{
private:
    Dungeon *dungeon;
    size_t dungeon_size;

public:
    Game(size_t dungeon_size = DUNGEON::DUNGEON_SIZE);
    ~Game();
    void init();
    void gameloop();
    bool play();
};