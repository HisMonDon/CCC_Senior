#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, i; cin>>N;

    for (int x = 0 ;x < N; x ++) {
        cin>>i;
        bool found = false;
        for (int y = 0; y < grid.size(); y++) {
            if (grid[y][0] == i) {
                grid[y][1] ++;
                found = true;
                break;
            }
        }
        if (!found) {
            grid.push_back({i, 1});
        }
    }
    if (grid.size() == 1) {
        cout<<"0";
        return 0;
    }
    sort(grid.begin(), grid.end(), [](const vector<int>&a,const vector<int>&b) {
        return a[1] > b[1];
    });
    if (grid[0][1] == grid[1][1]) {
        for (int x = grid.size() - 1; x >= 0; x--) {
            if (grid[x][1] == grid[0][1]) {
                break;
            }
            grid.erase(grid.begin() + x);
        }
        sort(grid.begin(), grid.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] > b[0];
        });
        int ans = grid[0][0] - grid[grid.size() - 1][0];
        cout<<ans;
    } else {
        int max = grid[0][0];
        int ans = 0;
        for (int x = grid.size() - 1; x >= 0; x--) {
            if (grid[x][1] == grid[1][1]) {
                break;
            }
            grid.erase(grid.begin() + x);
        }
        for (int x = 0; x < grid.size(); x++) {
            if (abs(max - grid[x][0]) > ans) {
                ans = abs(max - grid[x][0]);
            }
        }
        cout<<ans;
    }
}
