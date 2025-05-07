#pragma once

#include <iostream>
#include <ctime>
#include <vector>

const size_t DUNGEN_SIZE = 5;
const size_t MONSTER_DMG = 10;
const size_t TREASURE_SCORE = 20;
const size_t PLAYER_INIT_HP = 100;
const size_t PLAYER_INIT_SCORE = 0;
const size_t PLAYER_INIT_POS_X = 0;
const size_t PLAYER_INIT_POS_Y = 0;

enum Room
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
    Position(size_t x = PLAYER_INIT_POS_X, size_t y = PLAYER_INIT_POS_Y);
    Position(const Position &position);
};

struct Stats
{
    size_t hp, score;
    Stats(size_t hp = PLAYER_INIT_HP, size_t score = PLAYER_INIT_SCORE);
    Stats(const Stats &stats);
};

struct DungenRoom
{
    Room type;
    bool is_revealed;
    bool is_wall;
    DungenRoom(Room type = Room::EMPTY, bool is_revealed = false, bool is_wall = false);
    DungenRoom(const DungenRoom &dungeonroom);
};

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
    DungenRoom **rooms;
    Player *player;

public:
    Dungeon(size_t size);
    ~Dungeon();
    void display();
    void generate();
};

class Game
{
private:
    Dungeon *dungeon;
    size_t dungeon_size;

public:
    Game(size_t dungeon_size = DUNGEN_SIZE);
    ~Game();
    bool play();
    void gameloop();
};