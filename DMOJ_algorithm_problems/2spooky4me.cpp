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
    vector<vector<int>> pairs;
    vector<int> values;
    int n, t, limit, a, b, s;
    cin>>n>>t>>limit;
    for(int x = 0; x < n; x++){
        cin>>a>>b>>s;
        int index = 0;
        pairs.push_back({a, s});
        pairs.push_back({b + 1, -1*s});
    }
    sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>&b){
        return a[0] < b[0];
    });
    /*for(vector<int> x : pairs){
        for(int y : x){
            cout<<y<<", ";
        }
        cout<<"\n";
    }*/
    int amount = 0;
    for(int x = 0; x < pairs.size() - 1; x++){
        amount+= pairs[x][1];
        if(amount >= limit){
            t -= (pairs[x+1][0] - pairs[x][0]);//might need to -1?
        }
    }
    cout<<t;
}
