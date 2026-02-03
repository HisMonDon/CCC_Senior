#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> grid;
vector<vector<int>> steps;

void getInput(){
    string n;
    for(int x = 0; x < 10; x ++){
        grid.push_back(vector<string>{});
        for(int y = 0; y < 9; y++){
            cin>>n;
            grid[x].push_back(n);
        }
    }
}
int findSum(string entities){
    //cout<<entities<<", ";
    int sum = 0;
    for(int x = 0; x + 1 < (int)entities.size(); x += 3){
        // cout<<entities[x] - 65<<", "<<entities[x+1] - 48 - 1<<")";
        if(grid[entities[x] - 65][entities[x+1] - 48 - 1][0] <= 57 && grid[entities[x] - 65][entities[x+1] - 48 - 1][0] >= 48){
            sum += stoi(grid[entities[x] - 65][entities[x+1] - 48 - 1]);
        } else{
            //cout<<endl;
            return -1;
        }
    }
    // cout<<endl;
    return sum;
}
int main(){
    getInput();
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 9; y++){
            if(grid[x][y][0] > 57 || grid[x][y][0] < 48){
                int sum = findSum(grid[x][y]);
                if(sum == -1){
                    //cout<<"no";
                    steps.push_back({x, y});
                } else {
                    grid[x][y] = to_string(sum);
                    //  cout<<"yes";
                }
            }
        }
    }

    bool isFound;
    while (true){
        isFound = false;
        for(int x = steps.size() - 1; x >= 0; x--){
            int sum = findSum(grid[steps[x][0]][steps[x][1]]);
            if(sum != -1){
                grid[steps[x][0]][steps[x][1]] = to_string(sum);
                steps.erase(steps.begin() + x);
                isFound = true;
            }
        }
        if(!isFound){
            for(vector<int> x : steps){
                grid[x[0]][x[1]] = "*";
            }
            break;
        }
    }
    int index = 0;
    for(vector<string> x : grid){
        for(string y : x){
            cout<<y;
            if(index != 8){
                cout<<" ";
            }
            index++;
        }
        index = 0;
        cout<<endl;
    }
}
