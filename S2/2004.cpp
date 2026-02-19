#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid; //3 elements [0]: yodeller index, [1]: worst rank, [2]: score
int n, r;
int getIndex(int i){
    for(int x = 0; x < n; x++){
        if(grid[x][0] == i){
            return x;
        }
    }
}
int main(){
    cin>>n>>r; int i;
    for(int x = 0; x < n; x++){
        grid.push_back({x, 0, 0});
    }
    for(int x = 0; x < r; x++){
        for(int y = 0; y < n; y++){
            cin>>i; grid[getIndex(y)][2] += i;
        }
        sort(grid.begin(), grid.end(), [](vector<int>&a, vector<int>&b){return a[2] > b[2];});
        int rank = 0;
        int prevscore = INT_MAX;
        for(int z = 0; z < n; z++){
            if(grid[z][2] != prevscore){
                rank++;
            }
            if(grid[z][1] < rank){
                grid[z][1] = rank;
            }
            prevscore = grid[z][2];
        }
    }
    vector<vector<int>>winners;
    int maxScore = grid[0][2];
    for(vector<int> x : grid){
        if(x[2] != maxScore){break;}
        winners.push_back(x);
    }
    sort(winners.begin(), winners.end(), [](vector<int>&a, vector<int>&b){return a[0] < b[0];});
    for(vector<int> x : winners){
        cout<<"Yodeller "<<x[0] + 1<<" is the TopYodeller: score "<<x[2]<<", worst rank "<<x[1]<<"\n";
    }
}
