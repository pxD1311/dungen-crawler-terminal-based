#include <ctime>
#include <cstdlib>
#include <iostream>

inline bool seed_once = []()
{ std::srand(std::time(nullptr)); return true; }();

inline int randint(int min, int max)
{
    if (min > max)
        std::swap(min, max);
    else if (min == max)
        return max;

    return min + std::rand() % (max - min + 1);
}