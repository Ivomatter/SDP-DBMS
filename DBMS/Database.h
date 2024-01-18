#pragma once
#ifndef DATABASE_H
#define DATABASE_H


#include <string>

using std::string;

class Database
{
private:
    string path;
public:
    Database(string dbName, string fullPath);

    string getDirectory();

    static Database createEmpty(string dbName);     
};

#endif // !DATABASE_H