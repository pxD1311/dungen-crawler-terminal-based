#include <iostream>
#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());

inline int randint(int min, int max)
{
    if (min > max)
        std::swap(min, max);
    else if (min == max)
        return min;

    static std::uniform_int_distribution<> dist;
    return dist(gen, std::uniform_int_distribution<>::param_type(min, max));
}