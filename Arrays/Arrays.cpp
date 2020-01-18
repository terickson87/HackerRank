
// https://www.hackerrank.com/challenges/arrays-introduction/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int nVals = 0;
    cin >> nVals;

    int* valsArray = new int[nVals];
    for(int iVal = 0; iVal < nVals; ++iVal){
        cin >> valsArray[iVal];
    }

    for(int iVal = nVals - 1; iVal >= 0; --iVal){
        cout << valsArray[iVal];
        if (iVal != 0) {
            cout << " ";
        }
    }

    delete [] valsArray;
    
    return 0;
}