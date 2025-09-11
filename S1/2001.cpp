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
vector<vector<string>> cards = vector<vector<string>> (4, vector<string>());
vector<int> points = vector<int>(4, 0);
vector<string> userChars;
int main(){
    string userInput;
    cin >> userInput;
    string stochar;
    int index = -1;
    int total = 0;
    for(char x :  userInput){
        stochar = "";
        stochar.push_back(x);
        if (stochar == "C" || stochar == "H" || stochar == "D" || stochar == "S"){
            //cout<<stochar;
            index ++ ;
            continue;
        }
        cards[index].push_back(stochar);
    }
    for(int x = 0; x < 4; x ++){
        for(string card : cards[x]){
            if(card == "A"){
                total += 4;
                points[x] += 4;
                continue;
            }
            if(card == "K"){
                total += 3;
                points[x] += 3;
                continue;
            }
            if(card == "Q"){
                total += 2;
                points[x] += 2;
                continue;
            }
            if(card == "J"){
                total ++;
                points[x] += 1;
                continue;
            }
        }
        if(cards[x].size() <= 2){
            total += (3 - cards[x].size());
            points[x] += (3 - cards[x].size());
        }
    }
    cout<<"Cards Dealt              Points"<<endl;
    vector<string> names = {"Clubs ", "Diamonds ", "Hearts ", "Spades "};
    for(int x = 0; x < 4; x++){
        cout<<names[x];
        for(string y : cards[x]){
            cout<<y<< " ";
        }
        cout<<points[x]<<endl;
    }
    cout<<" Total "<< total;
    
}
