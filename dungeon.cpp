#include "game.hpp"

Dungeon::Dungeon(size_t size, Position init_position, Stats stats)
    : size(size)
{
    init(init_position, stats);
}
Dungeon::~Dungeon()
{
    delete player;
    for (size_t i = 0; i < size; i++)
        delete rooms[i];
    delete rooms;
}
void Dungeon::init(Position init_position, Stats stats)
{
    player = new Player(init_position, stats);

    rooms = new DungeonRoom *[size];
    for (size_t i = 0; i < size; i++)
        rooms[i] = new DungeonRoom[size];
}
void Dungeon::display()
{
    Position player_pos = player->getPos();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (player_pos.x == i && player_pos.y == j)
                std::cout << " *";
            else
                std::cout << "  ";
            std::cout << rooms[i][j];
        }
        std::cout << std::endl;
    }
}
void Dungeon::generate()
{

    for (size_t i = 0; i < DUNGEON::MONSTER_NUM; i++)
    {
        int rand_var_1 = randint(1, size);
        int rand_var_2 = randint(1, size);

        if (rooms[rand_var_1][rand_var_2].type == ROOM::EMPTY || rooms[rand_var_1][rand_var_2].type == ROOM::MONSTER)
            rooms[rand_var_1][rand_var_2].type = ROOM::MONSTER;
    }

    for (size_t i = 0; i < DUNGEON::TRAP_NUM; i++)
    {
        int rand_var_1 = randint(1, size);
        int rand_var_2 = randint(1, size);

        if (rooms[rand_var_1][rand_var_2].type == ROOM::EMPTY || rooms[rand_var_1][rand_var_2].type == ROOM::TRAP)
            rooms[rand_var_1][rand_var_2].type = ROOM::TRAP;
    }

    for (size_t i = 0; i < DUNGEON::TREASURE_NUM; i++)
    {
        int rand_var_1 = randint(1, size);
        int rand_var_2 = randint(1, size);

        if (rooms[rand_var_1][rand_var_2].type == ROOM::EMPTY || rooms[rand_var_1][rand_var_2].type == ROOM::TREASURE)
            rooms[rand_var_1][rand_var_2].type = ROOM::TREASURE;
    }
    rooms[size][size].type = ROOM::EXIT;
}