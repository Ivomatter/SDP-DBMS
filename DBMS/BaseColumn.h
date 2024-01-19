#pragma once

#include <string>

using std::string;

class BaseColumn {
public:
    virtual bool addItem(const string& item) = 0;
};