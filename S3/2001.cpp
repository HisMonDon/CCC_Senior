#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> adj_matrix (26, vector<int>(26, 0));
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
bool bfs(int firstnum, int secondnum){
    for(int x = 0; x < adj_matrix[0].size(); x++){
        if(x == firstnum || x == secondnum){
            continue;
        }
        if(adj_matrix[0][x] == 1){
            return true;
        }
    }
    return false; // returns if no more paths found. if its false, its a good sign for potential B appearing, check in main code latr.
}

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
    
    printmatrix();
    
    return 0;
}
