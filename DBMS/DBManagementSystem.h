#pragma once
#ifndef DBMS_H
#define DBMS_H


#include <string>

#include "Database.h"

using std::string;


class DBManagementSystem
{

public:
    static Database createEmptyDB(string &dbName);
};

#endif // !DBMS_H