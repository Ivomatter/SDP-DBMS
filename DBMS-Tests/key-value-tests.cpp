#include "doctest.hpp"

#include <string>
#include <filesystem>

#include "../DBMS/DBManagementSystem.h"

using std::string;
namespace filesystem = std::filesystem;

//TEST_CASE("Store and retrieve a key value") {
//
//	//Story:-
//	//	[Who] As a database user
//	//	[What] I need to store and retrieve a value 
//	//	[Value] So I can store data for later
//	SUBCASE("Basic set and get") {
//		string dbName("keyValueDb");
//		Database db(DBManagementSystem::createEmptyDB(dbName));
//
//		//We know we have been successful when:
//		//1. The retrieved value is the same as the stored value
//		string key("defaultKey");
//		string value("defaultValue");
//		db.setKeyValue(key, value);
//		REQUIRE(value == db.getKeyValue(key));
//
//		db.destroy();
//		REQUIRE(!filesystem::exists(filesystem::status(db.getDirectory())));
//	}
//}