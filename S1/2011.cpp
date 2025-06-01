#include <iostream>
using namespace std;
int main() {
    int numberOfLines;
    cin >> numberOfLines;
    cin.ignore();
    int numberOfS = 0;
    int numberOfT = 0;
    string line;
    for (int x = 0; x < numberOfLines; x++) {
        getline(cin, line);
        for (char mychar: line) {
            if (mychar == 'S' || mychar == 's'){
                numberOfS ++;
            } else if (mychar == 'T' || mychar == 't') {
                numberOfT ++;
            }
        }
        //cout<<"Number of T: " << numberOfT << endl << "Line: "<< line;
    }
    if (numberOfT <= numberOfS) {
        cout<<"French";
    } else {
        cout<<"English";
    }
}
