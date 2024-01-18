#include "Database.h"

Database::Database(string dbName, string fullPath)
{

}

string Database::getDirectory()
{
    return "Placeholder";
}

Database Database::createEmpty(string dbName)
{
    return Database("Placeholder", "Placeholder");
}
