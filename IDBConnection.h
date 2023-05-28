#pragma once
#include <string>

class IDBConnection
{
public:
    bool virtual open(const char *, const char *, const char *, const char *) = 0;
    void virtual close() = 0;
    int virtual exeQuery(const char *) = 0;
};