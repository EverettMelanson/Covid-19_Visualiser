/*
Author: Everett Melanson
Description: Contains functions to pharse, sort, store and display covid-19 data
Date: October 7, 2020
*/

#include "Record.h"

#ifndef PROCESSING_H
#define PROCESSING_H

class Processing
{
private:
    static bool AscNewCaseSort(Record first, Record second);
    static bool DesNewCaseSort(Record first, Record second);
    static bool AscNewDeathSort(Record first, Record second);
    static bool DesNewDeathSort(Record first, Record second);
    static bool AscNewRecoverySort(Record first, Record second);
    static bool DesNewRecoverySort(Record first, Record second);
    static bool AscTotalCaseSort(Record first, Record second);
    static bool DesTotalCaseSort(Record first, Record second);
    static bool AscTotalDeathSort(Record first, Record second);
    static bool DesTotalDeathSort(Record first, Record second);
    static bool AscTotalRecoverySort(Record first, Record second);
    static bool DesTotalRecoverySort(Record first, Record second);

public:
    void getCovidData(std::vector<Record> &countryData);
    void sortData(int sortBy, int sortType, std::string &sorted, std::vector<Record> &countryData);
    void graphData(int sortBy, int sortType, std::string sorted, std::vector<Record> countryData);
    
};
#endif