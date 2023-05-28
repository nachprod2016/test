#include "DBConnection.h"
#include <iostream>

bool DBConnection::open(const char * h, const char * l, const char * p, const char * DB)
{
    mysql_init(&mysql);
    mysql_set_character_set(&mysql, "utf8");
    if (mysql_real_connect(&mysql, h, l, p, DB, 0, NULL, 0) == NULL)
    {
        return false;
    }
    mysql_query(&mysql, "create table if not exists users (u_id int auto_increment primary key, login varchar(255), password varchar(255))");
    mysql_query(&mysql, "create table if not exists chats (c_id int auto_increment primary key, user1 varchar(255), user2 varchar(255))");
    mysql_query(&mysql, "create table if not exists messages (m_id int auto_increment primary key, c_id int, author varchar(255), message varchar(1000))");
    return true;
}

void DBConnection::close()
{
    mysql_close(&mysql);
}

int DBConnection::exeQuery(const char * query)
{
    int a = mysql_query(&mysql, query);
    mysql_free_result(res);
    return a;
}