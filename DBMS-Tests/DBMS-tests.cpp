
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.hpp"

#include <filesystem>
#include <string>

#include "../DBMS/DBManagementSystem.h"


using std::string;
namespace filesystem = std::filesystem;

TEST_CASE("db-create - [createEmptyDb]") {

    // Story:
    //   [Who]   As a database administrator
    //   [What]  I need to create a new empty database
    //   [Value] So I can later store and retrieve data
    SUBCASE("Default settings") {
        string dbName = "emptyDB";
        Database db(DBManagementSystem::createEmptyDB(dbName));
        //We know we have been successful when:
        //1. We have a valid database reference returned
        //2. There exists a specific directory for the database on the file system
        REQUIRE(filesystem::is_directory(filesystem::status(db.getDirectory())));
        // C++17 Ref: https://en.cppreference.com/w/cpp/filesystem/is_directory

        //3. The database folder is empty (i.e. no data yet)
        const auto& p = filesystem::directory_iterator(db.getDirectory());
        REQUIRE(p == end(p)); 
        //i.e. the start reading byte is the same as the end one, 
        //therefore the folder is empty.

    }
}