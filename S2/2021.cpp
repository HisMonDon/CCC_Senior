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
 //this time i will (try to) use psa
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m, n, k; 
    cin>>m>> n>> k;
    int sum = 0;
    vector<int> rows(m, 0); //treat this as vertical
    vector<int> cols(n, 0); //treat this as horizontal
    char t; int i;
    for(int x = 0; x < k; x++){
        cin>>t>>i;
        if(t == 'R') {
            rows[i-1] += 1;
        } else{
            cols[i-1] += 1;
        }
    }
    
    /*for(int x : rows){
        cout<<x <<", ";
    } cout<<endl;
    for(int x : cols){
        cout<<x<<", ";
    }*/
    for(int x: rows){
        for(int y : cols){
            if((y + x ) % 2 == 1){
                sum++;
            }
        }
    }
    cout<<sum;
}
