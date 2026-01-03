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
    int N;
    cin>> N;
    int i;
    vector<int> ans (N, INT_MAX);
    vector<int> v;
    for(int x = 0; x < N; x++){
        cin>>i;
        v.push_back(i);
    }
    for(int x = 1; x <= N; x++){
        int accumulator = 0;
        for(int y = 0; y < x && y < N - x + 1; y++){
            accumulator += abs(v[x-1 + y] - v[x - 1 - y]);
            if(ans[2*y] > accumulator){
                ans[2*y] = accumulator;
            }
        }
    }
    for(int x = 1; x <= N - 1; x++){
        int accumulator = 0;
        for(int y = 0; y < x && y < N - x; y++){
            accumulator += abs(v[x + y] - v[x - 1 - y]);
            if(ans[2*y + 1] > accumulator){
                ans[2*y + 1] = accumulator;
            }
        }
    }
    for(int x : ans){
        cout<<x<<" ";
    }
}

