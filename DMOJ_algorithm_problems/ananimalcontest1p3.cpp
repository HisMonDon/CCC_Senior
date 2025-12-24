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

bool isEven(int x){
    if(x % 2 == 0) return true; return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t, nh; cin >> t >> nh;
    if((!isEven(t) && isEven(nh)) || (nh > t) || (isEven(t) && !isEven(nh))){
        cout<<"-1\n"; return 0;
    } 
     //let the first number be 1 regardless of wtv happens
    /*Possibilities:
    - e o
    - e e
    - o e 
    - o o
    tackle each case by itself
    */
    //if(isEven(t)){//nh must be even
        if(t == nh){
            for(int x = 0; x < nh - 1; x++){
                cout<<"1 ";
            }
            cout<<"1\n"; return 0;
        }
        bool isEven = true;
        int count = 0;
        for(int x = 1; x <= t - nh; x++){
            if(isEven){
                if(x == t) {cout<<"2\n"; return 0;} //no trailing ws
                cout<<"0 ";
            } else{
                if(x == t) {cout<<"1\n"; return 0;}
                cout<<"1 ";
            }
            isEven = !isEven;
            count ++;
        }
        for(int x = count; x < t - 1; x++){
            cout<<"1 ";
        }
        cout<<"0\n"; return 0;
   // }
    //now must be odd

    //remember to \n
}
