#pragma once

#include <cstdarg>
#include <cstdio>
#include <iostream>

namespace Console {

inline void Info(const char* message)
{
    std::cout << message << std::endl;
}

inline void InfoF(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    std::vprintf(fmt, args);
    va_end(args);
}

} // namespace Console

#define DEBUG_INFO

#ifdef DEBUG_INFO
#define LOG(fmt, ...) Console::InfoF(fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) std::wprintf(fmt, ##__VA_ARGS__)
#else
#define LOG(...)
#define LOGW(...)
#endif
