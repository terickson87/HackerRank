
// https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int aVal;
    cin >> aVal;

    int bVal;
    cin >> bVal;

    for(int iVal = aVal; iVal <= bVal; ++iVal){
        if(iVal == 1) {
            cout << "one\n";

        } else if(iVal == 2) {
            cout << "two\n";
            
        } else if(iVal == 3) {
            cout << "three\n";
            
        } else if(iVal == 4) {
            cout << "four\n";
            
        } else if(iVal == 5) {
            cout << "five\n";
            
        } else if(iVal == 6) {
            cout << "six\n";
            
        } else if(iVal == 7) {
            cout << "seven\n";
            
        } else if(iVal == 8) {
            cout << "eight\n";
            
        } else if(iVal == 9) {
            cout << "nine\n";
            
        } else {
            if (iVal % 2 == 0) {
                cout << "even\n";
            } else {
                cout << "odd\n";
            }
        }
    }
    return 0;
}

