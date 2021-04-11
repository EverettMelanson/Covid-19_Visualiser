/*
Author: Everett Melanson
Description: Contains functions to pharse, sort, store and display covid-19 data
Date: October 7, 2020
*/
#include <string>
#ifndef RECORD_H
#define RECORD_H

class Record
{
private:
    std::string name;
    std::string code;
    int newCases;
    int newDeaths;
    int newRecovery;
    int totalCases;
    int totalDeaths;
    int totalRecovery;

public:
    Record(std::string _name, std::string _code, int _newCases, int _newDeaths, int _newRecovery, 
        int _totalCases, int _totalDeaths, int _totalRecovery);
    ~Record();
    
    int getNewCases();
    int getNewDeaths();
    int getNewRecovery();
    int getTotalCases();
    int getTotalDeaths();
    int getTotalRecovery();
    std::string getCountryCode(){return code;}
    
};
#endif