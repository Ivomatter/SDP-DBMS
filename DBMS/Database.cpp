#include "Database.h"

#include <iostream>
#include <fstream>
#include <filesystem>

namespace filesystem = std::filesystem;

Database::Database(string dbName, string fullPath) :
    _dbName(dbName), _dbPath(fullPath) {};

string Database::getDirectory()
{
    return _dbPath;
}

void Database::setKeyValue(string key, string value)
{
    std::ofstream out;

    size_t size = value.size();
    out.open(_dbPath + "/" + key + "_string.kv", std::ios::out | std::ios::binary | std::ios::trunc);
    out.write((char*)&size, sizeof(size));
    out.write((char*)&value[0], size);
    out.close();
}

string Database::getKeyValue(string key) 
{
    string value;
    size_t size;
    std::ifstream in;

    in.open(_dbPath + "/" + key + "_string.kv", std::ios::in);
    in.read((char*)&size, sizeof(size));
    value.resize(size);
    in.read((char *)&value[0], size);
    in.close();
    return value;
}

void Database::destroy()
{
    if (filesystem::exists(_dbPath))
        filesystem::remove_all(_dbPath);
}

void Database::createTable(string tableName, vector<string> columnTypes, vector<string> columnNames)
{
    try {
        if (columnTypes.size() < 1 || columnTypes.size() != columnNames.size()) {
            //throw (std::invalid_argument("Mismatched or empty column creation request."));
        }
        else {
            Table newTable = Table(tableName, columnTypes, columnNames);
            _dbTables.push_back(newTable);
        }
    }
    catch (std::exception e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }
}

void Database::removeTable(string tableName)
{
}

bool Database::isEmpty()
{
    return _dbTables.empty();
}

Database Database::createEmpty(string dbName)
{
    if (!filesystem::exists(DEFAULT_DIRECTORY)) {
        filesystem::create_directory(DEFAULT_DIRECTORY);
    }
    string dbFolder = DEFAULT_DIRECTORY + "/" + dbName;
    if (!filesystem::exists(dbFolder)) {
        filesystem::create_directory(dbFolder);
    }
    return Database(dbName, dbFolder);
}
