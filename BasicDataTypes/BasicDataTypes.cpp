
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int intVar = 0;
    long longVar = 0;
    char charVar;
    float floatVar = 0.0;
    double doubleVar = 0.0;

    scanf("%d %ld %c %f %lf", &intVar, &longVar, &charVar, &floatVar, &doubleVar);
    
    printf("%d\n", intVar);
    printf("%ld\n", longVar);
    printf("%c\n", charVar);
    printf("%.3f\n", floatVar);
    printf("%.9f\n", doubleVar);

    return 0;
}