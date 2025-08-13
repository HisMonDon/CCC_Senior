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

vector<vector<int>> factors;
void getFactors(int num){
    int x = 1;
    while (x < num/x){
        if(num % x == 0){//bigger first
            if(x > num/x){
                factors.push_back({x, num/x});
            } else{
                 factors.push_back({num/x, x}); 
            }
        }
        x++;
    }
    //===================================================
    /*for(vector<int> x: factors){
        cout<<"[";
        for(int y : x){
            cout<<y<<", ";
        }
        cout<<"], ";
    }
    cout<<endl;*/
}
int doOperation(string subOrAdd, int index){
    if(subOrAdd == "add"){
        return factors[index][0] + factors[index][1];
    }
    return factors[index][0] - factors[index][1]; //first is always bigger
}
bool isNasty(){
    //int numToCheck = 0;
    for(int _ = 0; _ < factors.size() - 1; _++){
        int factorSum = doOperation("add", _);
        int factorDiff = doOperation("diff", _); //might delete later
        for(int x = _ + 1; x < factors.size(); x++){
            if(factorSum == doOperation("diff", x) || factorDiff == doOperation("add", x)){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int numbersToBeTested;
    cin>>numbersToBeTested;
    int userInput;
    for(int x = 0; x < numbersToBeTested; x++){
        factors.clear();
        cin>>userInput;
        getFactors(userInput);
        if(isNasty()){
            cout<<userInput<<" is nasty\n";
        } else{
            cout<<userInput<<" is not nasty\n";
        }
    }
    return 0;
}
