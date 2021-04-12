/*
Author: Everett Melanson
Description: Contains functions to pharse, sort, store and display covid-19 data
Date: October 7, 2020
*/


#include "Processing.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<Record> countryData;
    int sortType, sortBy;
    string sorted;  

    //Recieves sorting method from user
    cout << "Sort by: 1-New Cases 2-New Deaths 3-New Recovered 4-Total Cases 5-Total Deaths 6-Total Recovered"
         << "\n";
    cin >> sortBy;
    cout << "Sort Type: 1-Ascending 2-Descending"
         << "\n";
    cin >> sortType;

    Processing process;
    process.getCovidData(countryData);
    process.sortData(sortBy, sortType, sorted, countryData);
    process.graphData(sortBy, sortType, sorted, countryData);

    return 0;
}
