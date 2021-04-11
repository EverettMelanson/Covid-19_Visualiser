/*
Author: Everett Melanson
Description: Contains functions to pharse, sort, store and display covid-19 data
Date: October 7, 2020
*/
#include "Record.h"

//Constructor
Record::Record(std::string _name, std::string _code, int _newCases, int _newDeaths, int _newRecovery, int _totalCases, int _totalDeaths, int _totalRecovery)
{
    name = _name;
    code = _code;
    newCases = _newCases;
    newDeaths = _newDeaths;
    newRecovery = _newRecovery;
    totalCases = _totalCases;
    totalDeaths = _totalDeaths;
    totalRecovery = _totalRecovery;
}

//Getter methods used to access record data
int Record::getNewCases()
{
    return newCases;
}

int Record::getNewDeaths()
{
    return newDeaths;
}

int Record::getNewRecovery()
{
    return newRecovery;
}

int Record::getTotalCases()
{
    return totalCases;
}

int Record::getTotalDeaths()
{
    return totalDeaths;
}

int Record::getTotalRecovery()
{
    return totalRecovery;
}

Record::~Record() {}
