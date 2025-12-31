#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <climits>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
    string s;
    long long c; 
    cin>>s>>c;
    string number = "";
    long long total = 0;
    vector<char> character;
    vector<long long> frequency;
    for(char x : s){
        if (x <= 122 && x >= 97){
            if(number != ""){
                frequency.push_back(stoll(number));
                total += stoll(number);
            } 
            character.push_back(x);
            number = "";
        } else{
            number += x;
        }
    }
    frequency.push_back(stoll(number)); total += stoll(number);
    c++;
    c = c % total;
    if(c == 0){
        cout<<character.back();
        return 0;
    }
    for(int x = 0; x < frequency.size(); x++){
        c -= frequency[x];
        if(c <= 0){
            cout<<character[x];
            return 0;
        }
    }
}

