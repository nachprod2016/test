#include "Tester.h"

void Tester::TestInterface(IDBConnection & ob)
{
    ob.open("localhost", "chatServer", "chatPassword", "ChatDB");
    ob.exeQuery("select * from users;");
    ob.exeQuery("select * from chats;");
    ob.exeQuery("select * from messages;");
    ob.close();
}

void Tester::TestClassThatUseDB(IDBConnection & ob, classThatUseDB & t)
{
    t.openConnection(ob);
    t.useConnection("select * from users;");
    t.useConnection("select * from chats;");
    t.useConnection("select * from messages;");
    t.closeConnection();
}