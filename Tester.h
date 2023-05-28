#pragma once
#include "MockDBConection.h"
#include "classThatUseDB.h"

class Tester
{
public:
    Tester() = default;
    ~Tester() = default;
    void TestInterface(IDBConnection &);
    void TestClassThatUseDB(IDBConnection &, classThatUseDB &);
};
