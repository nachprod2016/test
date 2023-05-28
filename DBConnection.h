#pragma once

#include "IDBConnection.h"
#include "/usr/include/mysql/mysql.h"

class DBConnection : public IDBConnection
{
private:
    MYSQL mysql;
    MYSQL_RES* res;
public:
    DBConnection() = default;
    ~DBConnection() = default;
    bool open(const char *, const char *, const char *, const char *) override;
    void close() override;
    int exeQuery(const char *) override;
};