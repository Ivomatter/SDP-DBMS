#include "doctest.hpp"

#include <string>
#include <vector>
#include <filesystem>

#include "../DBMS/DBManagementSystem.h"

using std::string;
using std::vector;
namespace filesystem = std::filesystem;

TEST_CASE("Create Column") {
	//Story:-
	// [Who] As a database administrator
	// [What] I need to create a new column
	// [Value] So that I may add it to a table to store data

	SUBCASE("Basic column creation") {
		string columnName = "Name";
		string columnType = "string";

		BaseColumn* column = ColumnFactory::createColumn(columnType, columnName);
		//We know that we are successful when:
		// 1.The column's types are correct and we can
		// add a record of the corressponding type to the column,
		// but not a record of other types.

		
		REQUIRE(column->addItem("Michael Jordan"));
		REQUIRE(column->addItem("54"));

		BaseColumn* intColumn = ColumnFactory::createColumn("int", "numbers");

		REQUIRE(intColumn->addItem("523"));
		REQUIRE(!intColumn->addItem("as4f"));
	}
}


TEST_CASE("Create table") {

	string dbName = "tableDb";
	Database db = DBManagementSystem::createEmptyDB(dbName);
	//Story:-
	// [Who] As a database administrator
	// [What] I want to create a table
	// [Value] So that I may store data in the database

	SUBCASE("Creating a basic table") {
		string tableName = "basic";
		vector<string> types {"string","int", "bool" };
		vector<string> names {"Name", "fn", "isActive"};
		db.createTable(tableName, types, names);
		//We know we have been successful when:
		// 1.We have successfully created a table 
		REQUIRE(!db.isEmpty());

		db.removeTable(tableName);
	}
	//Creating a table should fail if:
	// 1. There is less than 1 type in the table
	SUBCASE("Attempting to create an empty table") {
		string tableName = "emptyTable";
		vector<string> types{};
		vector<string> names{"example", "anotherExample"};
		db.createTable(tableName, types, names);
		REQUIRE(db.isEmpty());
	}
	// 2. The number of names exceed the number of types of columns that we are given
	SUBCASE("Attempting to create a mismatched table") {
		string tableName = "mismatchedTable";
		vector<string> types{"string"};
		vector<string> names{"Names", "fn"};
		db.createTable(tableName, types, names);
		REQUIRE(db.isEmpty());
	}
}