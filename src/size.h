#pragma once

# if __cplusplus < 201703L

#include <QtGlobal>

#ifndef Q_OS_WIN

namespace std
{
    template <class T, size_t N>
    constexpr size_t size(const T (&array)[N]) noexcept
    {
        return array != nullptr ? N : 0;
    }

    template <class T>
    constexpr auto size(const T &c) -> decltype(c.size())
    {
        return c.size();
    }
}

# endif // Q_OS_WIN

#endif // __cplusplus
