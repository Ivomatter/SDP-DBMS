#pragma once

#include <stdexcept>
#include <iostream>

#include "Columns.h"

bool IntColumn::addItem(const string& item){
    try{
        if (checkIfStringIsNumerical(item)) {
            _columnData.push_back(std::stoi(item));
        }
        else {
            throw std::invalid_argument("Type mistmatch");
        }
    }
    catch (std::exception e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
};

bool IntColumn::checkIfStringIsNumerical(const string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; 
        }
    }
    return true;
}