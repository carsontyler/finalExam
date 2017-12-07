// File: HouseFunc
// Created by Carson Tyler on 12/07/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>

using namespace std;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    io::CSVReader<7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street",
                   "city", "state", "postalCode", "price");
    int id, number, postalCode;
    string street, city, state;
    double price;
    while(in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice hp1(id, number, street, city, state, postalCode, price);
        hp.push_back(hp1);
    }
    for(auto item:hp)
    {
        cout << item << endl;
    }
    cout << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by Price
    sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice rhs)
        {return lhs.getPrice() < rhs.getPrice();});
    cout << "Most Affordable Home: " << hp.front() << endl;
    cout << "Most Enpensive Home: " << hp.back() << endl << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    // Sort by State
    sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice rhs)
        {return lhs.getState() < rhs.getState();});
}
