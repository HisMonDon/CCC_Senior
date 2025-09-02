//   score: 6/15 passed first 2 test cases


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
int totalNotes;
int highestPitch;
int numOfGoodSamples;
vector<int> sheetMusic;
int currentGoodSamples;
bool isGood(vector<int> sample){
    vector<int> taken;
    for(int x : sample){
        for(int y : taken){
            if(x == y){
                return false;
            }
        }
        taken.push_back(x);
    }
}
int main(){
    cin>>totalNotes>>highestPitch>>numOfGoodSamples;
    currentGoodSamples = totalNotes;//samples with len 1 are good
    sheetMusic = vector<int>(totalNotes, 1);
    if(currentGoodSamples > numOfGoodSamples){
        cout<<-1;
        return 0;
    }
    int index;
    if((numOfGoodSamples - currentGoodSamples) % 2 == 1){
        index = 0;
    } else{
        index = 1;
    }
    if(currentGoodSamples == numOfGoodSamples){
        for(int x : sheetMusic){
            cout<<x<<" ";
        }
        return 0;
    }
    while(currentGoodSamples <= numOfGoodSamples){
        /*for(int x : sheetMusic){
            cout<<x<<" ";
        } cout<<endl;*/
        
        if(currentGoodSamples == numOfGoodSamples){
            for(int x : sheetMusic){
                cout<<x<<" ";
            }
            return 0;
        }
        if(index >= sheetMusic.size()){
            cout<<-1;
            return 0;
        }
        sheetMusic[index] = 2;
        if(index == sheetMusic.size() - 1 || index == 0){
            currentGoodSamples++;
        } else{
            currentGoodSamples += 2;
        }
        index += 2;
    }
    cout<<"error";
}
