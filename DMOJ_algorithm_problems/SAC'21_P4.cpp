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
    cin.sync_with_stdio(0);
    cin.tie(0);
    int numOfc, numOfq;
    cin>>numOfc>>numOfq;
    cin.ignore();
    string courseScores;
    getline(cin, courseScores);
    stringstream ss(courseScores);
    int _;
    vector<int> scores;
    vector<int> fcs;
    vector<int> bcs;
    fcs.push_back(0);
    while(ss >> _){
        scores.push_back(_);
        fcs.push_back(fcs.back() + _);
    }
    bcs.push_back(0);
    for(int x = scores.size() - 1; x >= 0; x--){
        if(x == scores.size() - 1){
            bcs.push_back(scores[x]);   
        } else{
            bcs.push_back(scores[x] + bcs.back());
        }
    }
    int totalSum = fcs.back();
    for(int x = 0; x < numOfq; x++){
        int a, b;
        cin>>a>>b;
        
        cout<<(totalSum -fcs[a - 1] - bcs[numOfc-b])/(b-a+1)<<"\n";
    }
    /*for(int x : fcs) cout<< x<<", ";
    cout<<endl;
    for(int x : bcs) cout<< x<<", ";*/
}
