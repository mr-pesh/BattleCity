#ifndef GLOBAL_H
#define GLOBAL_H

#define PLAYER_SPEED 6
#define ENEMY_SPEED (PLAYER_SPEED / 2)
#define SHELL_SPEED (PLAYER_SPEED * 2)

#define FRAME_DURATION 30

#define DEFAULT_UNIT_DIRECTION 0


/* Since the std::size expressions were added only in C++17 we will write our own implementation */

#include <ctime>

namespace std
{
    template <class T, std::size_t N>
    constexpr std::size_t size (const T (&array)[N]) noexcept
    {
        return array != nullptr ? N : 0;
    }

    template <class C>
    constexpr auto size(const C& c) -> decltype(c.size())
    {
        return c.size();
    }
}


#endif // GLOBAL_H
