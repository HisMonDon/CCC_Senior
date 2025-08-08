#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <climits>
#include <map>

using namespace std;
int returnIndex(vector<string> s, string substr){
    for(int x = 0; x < s.size(); x++){
        if(substr == s[x]){
            return x;
        }
    }
    return -1;
}
int main(){
    int numOfLetters;
    string letterInput;
    string decodedString = "";
    string numberInput;
    cin>>numOfLetters;
    //input
    vector<string> correspondingLetters;
    vector<string> correspondingBinary;
    for(int x = 0; x < numOfLetters; x++){
        cin>>letterInput>>numberInput;
        correspondingLetters.push_back(letterInput);
        correspondingBinary.push_back(numberInput);
    }
    cin>>letterInput;
    //_____________________________
    int index;
    while(true){
        if(letterInput.size() < 1){
            cout<<decodedString;
            break;
        }
        for(int x = 1 ; x <= letterInput.size(); x++){
            index = returnIndex(correspondingBinary, letterInput.substr(0, x));
            if(index != -1){
                decodedString += correspondingLetters[index];
                //cout<<"Letter Input before: " << letterInput <<"\nSubstring Found: " << letterInput.substr(0, x) <<"\nIndex: " << index << "\nLetter: "<< correspondingLetters[x]<<"\n";
                //cout<<"Letter List: ";
                /*for(string x : correspondingLetters){
                    cout<<x<<" ";
                }*/
                letterInput = letterInput.substr(x, letterInput.size()-1);
                //cout<<"\nLetter Input after: "<< letterInput<<"\n======================================\n";
                break;
            }
        }
    }
}
