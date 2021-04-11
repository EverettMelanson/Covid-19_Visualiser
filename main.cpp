/*
Author: Everett Melanson
Description: Contains functions to pharse, sort, store and display covid-19 data
Date: October 7, 2020
*/

#include "Record.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Function name: Ascending New Case Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (new case value) is smaller than the second, false if not
*/
bool AscNewCaseSort(Record first, Record second)
{
    return first.getNewCases() < second.getNewCases();
}

/*
Function name: Descending New Case Sort
Description: Compares 2 Records to determine if is the first is smaller than the second
Parameters: 2 Record Objects
Return: True, if first record (new case value) is larger than the second, false if not
*/
bool DesNewCaseSort(Record first, Record second)
{
    return first.getNewCases() > second.getNewCases();
}

/*
Function name: Ascending New Death Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (new Death value) is smaller than the second, false if not
*/
bool AscNewDeathSort(Record first, Record second)
{
    return first.getNewDeaths() < second.getNewDeaths();
}

/*
Function name: Descending New Death Sort
Description: Compares 2 Records to determine if is the second is smaller than the first
Parameters: 2 Record Objects
Return: True, if first record (New death value) is larger than the second, false if not
*/
bool DesNewDeathSort(Record first, Record second)
{
    return first.getNewDeaths() > second.getNewDeaths();
}

/*
Function name: Ascending New Recovery Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (new recovery value) is smaller than the second, false if not
*/
bool AscNewRecoverySort(Record first, Record second)
{
    return first.getNewRecovery() < second.getNewRecovery();
}

/*
Function name: Descending New Recovery Sort
Description: Compares 2 Records to determine if is the second is smaller than the first
Parameters: 2 Record Objects
Return: True, if first record (new recovery value) is larger than the second, false if not
*/
bool DesNewRecoverySort(Record first, Record second)
{
    return first.getNewRecovery() > second.getNewRecovery();
}

/*
Function name: Ascending Total Case Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (total case value) is smaller than the second, false if not
*/
bool AscTotalCaseSort(Record first, Record second)
{
    return first.getTotalCases() < second.getTotalCases();
}

/*
Function name: Descending Total Case Sort
Description: Compares 2 Records to determine if is the second is smaller than the first
Parameters: 2 Record Objects
Return: True, if first record (total case value) is larger than the second, false if not
*/
bool DesTotalCaseSort(Record first, Record second)
{
    return first.getTotalCases() > second.getTotalCases();
}

/*
Function name: Ascending Total Death Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (total death value) smaller than the second, false if not
*/
bool AscTotalDeathSort(Record first, Record second)
{
    return first.getTotalDeaths() < second.getTotalDeaths();
}

/*
Function name: Descending Total Death Sort
Description: Compares 2 Records to determine if is the second is smaller than the first
Parameters: 2 Record Objects
Return: True, if first record (total death value) larger than the second, false if not
*/
bool DesTotalDeathSort(Record first, Record second)
{
    return first.getTotalDeaths() > second.getTotalDeaths();
}

/*
Function name: Ascending Total Recovery Sort
Description: Compares 2 Records to determine if is the second is larger than the first
Parameters: 2 Record Objects
Return: True, if first record (total recovery value) smaller than the second, false if not
*/
bool AscTotalRecoverySort(Record first, Record second)
{
    return first.getTotalRecovery() < second.getTotalRecovery();
}

/*
Function name: Descending Total Recovery Sort
Description: Compares 2 Records to determine if is the second is smaller than the first
Parameters: 2 Record Objects
Return: True, if first record (total recovery value) larger than the second, false if not
*/
bool DesTotalRecoverySort(Record first, Record second)
{
    return first.getTotalRecovery() > second.getTotalRecovery();
}

/*
Function name: Get Covid Data
Description: Extracts, Pharses, and stores (in a vector) covid data
Parameters: A vector that stores Record Object to store each peice of covid data for each country
Return: returns void
*/
void getCovidData(vector<Record> &countryData)
{
    ifstream countryFile("ExampleInput.csv");
    string line;

    //skips first line
    getline(countryFile, line);

    //iterates over each line in the file and stores in line variable
    while (getline(countryFile, line))
    {
        stringstream lineStream(line);
        string s;
        int i = 0;
        string skip;

        string countryName, countryCode;
        int newCases, newDeaths, newRecovered;
        int totalCases, totalDeaths, totalRecovered;

        getline(lineStream, skip, '"');
        getline(lineStream, countryName, '"');


        //Stores each piece of data in variable in each line
        for (i; i < 11; i++)
        {
            getline(lineStream, s, ',');
            s.erase(remove(s.begin(), s.end(), '\"'), s.end());
            stringstream ss(s);
            switch (i)
            {
            case 1:
                countryCode = s;
                break;
            case 3:
                ss >> newCases;
                break;
            case 4:
                ss >> newDeaths;
                break;
            case 5:
                ss >> newRecovered;
                break;
            case 8:
                ss >> totalCases;
                break;
            case 9:
                ss >> totalDeaths;
                break;
            case 10:
                ss >> totalRecovered;
                break;
            }
        }
        //created a record of each countries Data and pushes it into the countryData vector
        Record newRecord(countryName, countryCode, newCases, newDeaths, newRecovered, totalCases, totalDeaths, totalRecovered);
        countryData.push_back(newRecord);
    }
}

/*
Function name: Sort Data
Description: Sorts covid data by 6 different parameters, each with acsending and descending options
Parameters: 2 integers which are input from user to determine sorting method, a string to store the selected sorting method
            and a vector of records to be sorted.
Return: returns void
*/
void sortData(int sortBy, int sortType, string &sorted, vector<Record> &countryData)
{
    //Uses user input to select the appropiate sorting method
   switch (sortBy)
    {
    case 1:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscNewCaseSort);
            sorted = "Acsending New Cases";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesNewCaseSort);
            sorted = "Descending New Cases";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    case 2:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscNewDeathSort);
            sorted = "Ascending New Deaths";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesNewDeathSort);
            sorted = "Descending New Deaths";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    case 3:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscNewRecoverySort);
            sorted = "Ascending New Recoveries";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesNewRecoverySort);
            sorted = "Descending New Recoveries";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    case 4:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscTotalCaseSort);
            sorted = "Ascending Total Cases";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesTotalCaseSort);
            sorted = "Descending Total Cases";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    case 5:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscTotalDeathSort);
            sorted = "Ascending Total Deaths";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesTotalDeathSort);
            sorted = "Descending Total Deaths";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    case 6:
        if (sortType == 1)
        {
            sort(countryData.begin(), countryData.end(), AscTotalRecoverySort);
            sorted = "Ascending Total Recoveries";
        }
        else if (sortType == 2)
        {
            sort(countryData.begin(), countryData.end(), DesTotalRecoverySort);
            sorted = "Descending Total Recoveries";
        }
        else
        {
            cout << "Invalid Input. Try Again."
                 << "\n";
            exit(1);
        }
        break;

    default:
        cout << "Invalid Input."
             << "\n";
        exit(1);
    }
}

/*
Function name: Sort Data
Description: Graphs sorted data in a text-based ui
Parameters: 2 integers which are input from user to determine graphing method, a string to print sorting method for legend
            and a vector of records to be graphed.
Return: returns void
*/
void graphData(int sortBy, int sortType, string sorted, vector<Record> countryData)
{

    //Creates a graph, calculates the value of each '#' and finds the relative size for each country
    int topResult, proportion, i;
    int test = countryData.size();
    for (i = 0; i < 10; i++)
    {
        cout << "| " << countryData[i].getCountryCode() << " ";

        switch (sortBy)
        {
        case 1:

            topResult = countryData[0].getNewCases();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getNewCases() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getNewCases() / proportion), '#') << "\n";
            break;

        case 2:
            topResult = countryData[0].getNewDeaths();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getNewDeaths() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getNewDeaths() / proportion), '#') << "\n";
            break;

        case 3:
            topResult = countryData[0].getNewRecovery();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getNewRecovery() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getNewRecovery() / proportion), '#') << "\n";
            break;

        case 4:
            topResult = countryData[0].getTotalCases();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getTotalCases() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getTotalCases() / proportion), '#') << "\n";
            break;

        case 5:
            topResult = countryData[0].getTotalDeaths();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getTotalDeaths() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getTotalDeaths() / proportion), '#') << "\n";
            break;

        case 6:
            topResult = countryData[0].getTotalRecovery();
            if (sortType == 1)
            {
                proportion = countryData[countryData.size() - 1].getTotalRecovery() / 50;
            }
            else if (sortType == 2)
            {
                proportion = topResult / 50;
            }
            cout << string(round(countryData[i].getTotalRecovery() / proportion), '#') << "\n";
            break;
        }
        cout << "| "
             << "\n";
    }

    //creates legend with size of each '#' and sorting method
    cout << "__________________________________________________"
         << "\n";
    cout << sorted << "; "
         << "Each # is Approx. " << proportion << " cases \n";
}

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

    getCovidData(countryData);
    sortData(sortBy, sortType, sorted, countryData);
    graphData(sortBy, sortType, sorted, countryData);

    return 0;
}
