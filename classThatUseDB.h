#pragma once
#include "IDBConnection.h"
#include <iostream>

class classThatUseDB
{
public:
    IDBConnection * connection;
public:
    classThatUseDB();
    ~classThatUseDB() = default;
    bool openConnection(IDBConnection &);
    bool closeConnection();
    int useConnection(const char *);
};