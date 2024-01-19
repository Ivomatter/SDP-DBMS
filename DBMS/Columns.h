#pragma once

#include "BaseColumn.h"
#include <string>
#include <vector>

using std::vector;

const string STRING_TYPE_SIGNATURE = "string";
const string INT_TYPE_SIGNATURE = "int";
const string FLOAT_TYPE_SIGNATURE = "float";
const string BOOL_TYPE_SIGNATURE = "bool";

class IntColumn : public BaseColumn
{
private:
    vector<int> _columnData;
public:
    bool addItem(const string& item) override;
    bool checkIfStringIsNumerical(const string& str);
};

class StringColumn : public BaseColumn
{
    bool addItem(const string& item) override { return true; };
};

class FloatColumn : public BaseColumn
{
    bool addItem(const string& item) override { return true; };
};

class BoolColumn : public BaseColumn
{
    bool addItem(const string& item) override { return true; };
};





