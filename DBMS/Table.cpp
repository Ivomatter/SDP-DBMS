#include "Table.h"

Table::Table(string name, vector<string> types, vector<string> names)
{
    for (int i = 0; i < types.size(); ++i) {
        BaseColumn* newColumn = ColumnFactory::createColumn(types[i], names[i]);
        _tableColumns.push_back(newColumn);
    }
    _tableName = name;
}
