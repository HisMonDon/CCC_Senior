#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> adj_matrix (26, vector<int>(26, 0));
vector<vector<int>> possible_paths;
vector<int> takenpathsbefore;
int disconnectingRoads = 0;
bool isinvector(vector<int> skib, int a, int b){
    for(int x = 0; x < skib.size()-1; x++){
        if(skib[x] == a && skib[x+1] == b){
            return true;
        }
    }
    return false;
}
void printmatrix(){
    for(vector<int> x : adj_matrix){
        for(int y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
void add_edge(int u, int v){
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}
bool isTaken(int num){
    for(int x : takenpathsbefore){
        if (x == num){
            return true;
        }
    }
    return false;
}
bool dfs(int firstnum){ //passes is originally zero
    bool foundAny = false;
    if(firstnum == 1){ //1 means its connected to B
        possible_paths.push_back(takenpathsbefore);
        return true;
    }
    for(int x = 0; x < adj_matrix[0].size(); x++){
        if(x == 0 || isTaken(x)){
            continue;
        }
        if(adj_matrix[firstnum][x] == 1){
                takenpathsbefore.push_back(x);
                if (dfs(x)){
                    bool result = true;
                    bool foundAny = true;
                    takenpathsbefore.pop_back();
                }
            }
        }
    takenpathsbefore.pop_back();
    return foundAny;
    }

     // returns if no more paths found. if its false, its a good sign for potential B appearing, check in main code latr.
//analyze all possible paths to B, and see if all of them have common links
int main(){
    string inputstring;
    while (true){
        cin>>inputstring;
        if(inputstring == "**"){
            break;
        }
        int num1 = static_cast<int>(inputstring[0]) - 65;
        int num2 = static_cast<int>(inputstring[1]) - 65;
        add_edge(num1, num2);
    }
    takenpathsbefore.push_back(0);
    if(dfs(0)){
        cout<<"ez";
    }
    bool isFound = true;
    for(int x = 0; x < possible_paths[0].size(); x++){
        for(vector<int> possiblePath : possible_paths){
            if(!isinvector(possiblePath, possible_paths[0][x], possible_paths[0][x+1])){
                isFound = false;
                break;
            }
        }
        if(isFound){
            disconnectingRoads++;
            cout<<static_cast<char>(possible_paths[0][x] + 65)<<static_cast<char>(possible_paths[0][x+1] + 65)<<endl;
        }
        isFound = true;
    }
    cout<<"There are "<<disconnectingRoads<<" disconnecting roads."<<endl;
    /*for(vector<int> x : possible_paths){
        for (int y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    printmatrix();
    */
    return 0;
}
