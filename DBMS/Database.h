#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "Table.h"

using std::string;
using std::vector;

const string DEFAULT_DIRECTORY = ".DBMS";

class Database
{
private:
    string _dbPath;
    string _dbName;

    vector<Table> _dbTables;
public:
    Database(string dbName, string fullPath);

    string getDirectory();

    void setKeyValue(string key, string value);
    string getKeyValue(string key);

    void destroy();

    void createTable(string tableName, vector<string> columnTypes, vector<string> columnNames);
    void removeTable(string tableName);
    bool isEmpty();

    static Database createEmpty(string dbName);     

};

#endif // !DATABASE_H