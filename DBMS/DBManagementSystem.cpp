#include "DBManagementSystem.h"

Database DBManagementSystem::createEmptyDB(string &dbName)
{
    return Database::createEmpty(dbName);   
}
