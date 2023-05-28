#include "MockDBConection.h"
#include "classThatUseDB.h"
#include "DBConnection.h"
#include "Tester.h"

//Тестирование мокобъекта
TEST(Test, test1)
{
    MockDBConection m;
    Tester t;
    EXPECT_CALL(m, open).Times(::testing::AtLeast(1));
    EXPECT_CALL(m, exeQuery).Times(::testing::AtLeast(3));
    EXPECT_CALL(m, close).Times(::testing::AtLeast(1));
    t.TestInterface(m);
}

//Тестирование мок-объекта через classThatUseDB 
TEST(Test, test2)
{
    MockDBConection m;
    classThatUseDB user;
    Tester t;
    EXPECT_CALL(m, open).Times(::testing::AtLeast(0));
    EXPECT_CALL(m, exeQuery).Times(::testing::AtLeast(3));
    EXPECT_CALL(m, close).Times(::testing::AtLeast(1));
    t.TestClassThatUseDB(m, user);
}

//Тестирование объектов classThatUseDB и DBConection.h
TEST(Test, test3)
{
    DBConnection db;
    EXPECT_EQ(db.open("localhost", "chatServer", "chatPassword", "ChatDB"), true);
    classThatUseDB u_DB;
    EXPECT_EQ(u_DB.openConnection(db), true);
    EXPECT_EQ(u_DB.useConnection("select * from users;"), 0);
    EXPECT_EQ(u_DB.closeConnection(), true);
    EXPECT_EQ(db.open("localhost", "chatServer", "chatPassword", "ChatDB1"), false);
    EXPECT_EQ(u_DB.openConnection(db), true);
    ASSERT_TRUE(u_DB.useConnection("select * from users;") != 0);
    ASSERT_TRUE(u_DB.closeConnection() == true);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}