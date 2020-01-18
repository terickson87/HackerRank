
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int debugFlag = 1;

void printPlineData(const vector <int> *pLineData) {
    cout << "Vector contents: ";
    for(unsigned int index = 0; index < pLineData->size(); ++index){
        cout << pLineData->at(index);
        if (index < pLineData->size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
}

vector <int>* getLine(const int numberOfVals) {
    vector <int> *pLineData = new vector <int>;
    int getVal;

    // cout << "Getting vector of " << numberOfVals << " values:" << endl;
    for (int iVal = 0; iVal < numberOfVals; ++iVal) {
        cin >> getVal;
        pLineData->push_back(getVal);
        // cout << "    Got value(" << iVal << "): " << getVal << endl;
    }

    // printPlineData(pLineData);
    
    return pLineData;
}

vector <unsigned int>* getLineUnsigned(const unsigned int numberOfVals) {
    vector <unsigned int> *pLineData = new vector <unsigned int>;
    unsigned int getVal;

    // cout << "Getting vector of " << numberOfVals << " values:" << endl;
    for (unsigned int iVal = 0; iVal < numberOfVals; ++iVal) {
        cin >> getVal;
        pLineData->push_back(getVal);
        // cout << "    Got value(" << iVal << "): " << getVal << endl;
    }

    // printPlineData(pLineData);
    
    return pLineData;
}

void deletePTVOIFVOPTVOI(vector <vector <int>*> &rVoptvoi) {
    // delete [V]ectors [O]f [I]nts [F]rom [V]ector [O]f [P]ointers [T]o [V]ector [O]f [I]nts
    while(!rVoptvoi.empty()) {
        delete rVoptvoi.back();
        rVoptvoi.pop_back();
    }
}

int main() {

    // get array index and value index
    const int numberOfArraysIndex = 0;
    const int numberOfQueriesIndex = 1;
    vector <unsigned int>* pParameters = getLineUnsigned(2);
    unsigned int numberOfArrays_n = pParameters->at(numberOfArraysIndex);
    unsigned int numberOfQueries_q = pParameters->at(numberOfQueriesIndex);

    // Get the arrays
    vector <vector <int>*> arrays;
    int numberOfValuesInArray;
    for(unsigned int iArray = 0 ; iArray < numberOfArrays_n ; ++iArray){
        cin >> numberOfValuesInArray;
        vector <int>* thisLine = getLine(numberOfValuesInArray);
        arrays.push_back(thisLine);
    }
    // cout << "Arrays vector size: " << arrays.size() << endl;

    // Get the queries
    vector <vector <int>*> queries;
    numberOfValuesInArray = 2;
    for(unsigned int iQuery = 0 ; iQuery < numberOfQueries_q ; ++iQuery){
        vector <int>* thisLine = getLine(numberOfValuesInArray);
        queries.push_back(thisLine);
    }
    // cout << "Queries vector size: " << queries.size() << endl;

    //Evaluate queries
    const int queryArrayIndex = 0;
    const int queryValueIndex = 1;

    // Extract and print the queries
     for (size_t iQuery = 0; iQuery < numberOfQueries_q; ++iQuery) {
        
        vector <int>* thisQuery = queries.at(iQuery);
        int arrayIndex = thisQuery->at(queryArrayIndex);
        int valueIndex = thisQuery->at(queryValueIndex);
        size_t arrayIndex2 = static_cast<size_t>(arrayIndex);
        size_t valueIndex2 = static_cast<size_t>(valueIndex);

        vector <int>* thisArray = arrays.at(arrayIndex2);
        int thisValue = thisArray->at(valueIndex2);

        cout << thisValue << endl;
    }

    // Clean up data
    deletePTVOIFVOPTVOI(queries);
    deletePTVOIFVOPTVOI(arrays);

    return 0;
}
