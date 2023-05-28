#include "classThatUseDB.h"

classThatUseDB::classThatUseDB() : connection(nullptr) {}

bool classThatUseDB::openConnection(IDBConnection & ob)
{
    connection = & ob;
    return true;
}

bool classThatUseDB::closeConnection()
{
    connection->close();
    connection = nullptr;
    return true;
}

int classThatUseDB::useConnection(const char * query)
{
    return connection->exeQuery(query);
}