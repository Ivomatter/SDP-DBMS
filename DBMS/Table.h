#pragma once
#ifndef TABLE_H
#define TABLE_H

#include "Columns.h"
#include "ColumnFactory.h"

class Table
{
private:
    vector<BaseColumn*> _tableColumns;
    string _tableName;
public:
    Table(string name,  vector<string> types, vector<string> names);
};


#endif

