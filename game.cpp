#include "game.hpp"

Game::Game(size_t dungeon_size)
    : dungeon_size(dungeon_size)
{
    init();
}
Game::~Game()
{
    delete dungeon;
}
void Game::init()
{
    Position init_pos = Position(PLAYER::INIT_POS_X, PLAYER::INIT_POS_Y);
    Stats init_stats = Stats(PLAYER::INIT_HP, PLAYER::INIT_SCORE);
    dungeon = new Dungeon(dungeon_size, init_pos, init_stats);
}

void Game::gameloop()
{
    char input;
    std::cout << "Welcome to Dungeon Crawler!" << std::endl;
    while (true)
    {
        play();
        std::cout << "Play again?(Y/n)?";
        std::cin >> input;
        if (input == 'n' || input == 'N')
            break;
    }
    std::cout << "Thanks for playing!" << std::endl;
}

bool Game::play()
{
    /*To be implemented*/
    char input;
    std::cin >> input;
    return true;
}