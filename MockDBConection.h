#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include "IDBConnection.h"

class MockDBConection : public IDBConnection
{
public:
    MOCK_METHOD(bool, open, (const char *, const char *, const char *, const char *), (override));
    MOCK_METHOD(int, exeQuery, (const char *), (override));
    MOCK_METHOD(void, close, (), (override));
};