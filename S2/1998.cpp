#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool getfactors(int mynumber) {
    int sum = 0;
    int compared = mynumber;
    for (int x = 1 ; x <= mynumber/2; x++) { // it is divided by 2 because anything more than half is not a factor
        if (mynumber % x == 0) {
            sum += x;
        }
    }
    if (sum == compared) {
        return true;
    }
    return false;
}
bool secondpart(int skib) {
    int sum = 0;
    int mynumber = skib;
    while (mynumber!= 0) {
        sum += pow (mynumber % 10 , 3);
        mynumber /= 10;
    }
    if (skib == sum) {
        return true;
    }
    return false;
}
int main() {
    for (int x = 1000; x <= 9999; x++) {
        if (getfactors(x)) {
            cout << x << " ";
        }
    }
    cout<<endl;
    for (int x = 100 ; x <= 999; x++) {
        if (secondpart(x)) {
            cout << x << " ";
        }
    }
    cout<< endl;
}
