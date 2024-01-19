#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>

#include "Columns.h"



using std::string;
using std::vector;
using std::unique_ptr;


class ColumnFactory
{
public:


    static BaseColumn* createColumn(const string& type,const string& name)
    {
        try {
            if (type == STRING_TYPE_SIGNATURE) {
                return new StringColumn();
            }
            else if (type == INT_TYPE_SIGNATURE) {
                return new IntColumn();
            }
            else if (type == BOOL_TYPE_SIGNATURE) {
                return new BoolColumn();
            }
            else if (type == FLOAT_TYPE_SIGNATURE) {
                return new FloatColumn();
            }
            throw(std::invalid_argument("Unsupported data type"));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            throw;
        }
        return nullptr;
    }
};

