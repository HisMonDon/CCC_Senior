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
    string a, b;
    bool found = false;
    cin>>a >> b;
    int count = 0;
    int maxCount = 0;
    for(int x = 0; x < a.size(); x++){
        if(x == b.size()){
            break;
        }
        count++;
        if(a.substr(a.size() - x - 1, x + 1) == b.substr(0, x+1) || b.substr(b.size() - x - 1, x + 1) == a.substr(0, x+1)){
            maxCount = count;
            found = true;
        }
    }
    if(!found){
        cout<<"0";
        return 0;
    }
    cout<<maxCount;
}

