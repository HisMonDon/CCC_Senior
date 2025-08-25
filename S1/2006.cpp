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


vector<char> motherGenes;
vector<char> fatherGenes;
bool checkIsPossible(char babyGene, int index){
    char char1;
    char char2;
    int lowerCount = 0;
    bool canBeLower = false;
    bool canBeUpper = false;
    vector <char> possibleGenes;
    if(isupper(motherGenes[index]) || isupper(fatherGenes[index]) || isupper(motherGenes[index + 1]) || isupper(fatherGenes[index + 1])){
        canBeUpper = true;
    }
    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 2; y++){
            if(!isupper(motherGenes[index + x]) && !isupper(fatherGenes[index + y])){
                canBeLower = true;
                break;
            }
        }
    }
    /*if(canBeLower){
        cout<<motherGenes[index]<<motherGenes[index + 1]<<" with " << fatherGenes[index]<<fatherGenes[index + 1]<< " can be lower"<<endl;
    }
    if(canBeUpper){
        cout<<motherGenes[index]<<motherGenes[index + 1]<<" with " << fatherGenes[index]<<fatherGenes[index + 1]<< " can be higher"<<endl;
    }
    cout<<"baby gene: "<<babyGene<<endl;*/
    if(isupper(babyGene)){
        if(canBeUpper){
            return true;
        } else{
            return false;
        }
    } else{
        if(canBeLower){
            return true;
        }
        return false;
    }
}
int main(){
    string userInput;
    int numOfBabies;
    cin>>userInput;
    bool canBeBaby;
    for(char x : userInput){
        motherGenes.push_back(x);
    }
    cin>>userInput;
    for(char x : userInput){
        fatherGenes.push_back(x);
    }
    cin>>numOfBabies;
    for(int _ = 0; _ < numOfBabies; _++){
        cin>>userInput;
        int babyIndex = 0;
        canBeBaby = true;
        for(int x = 0; x < 10; x += 2){
            if(!checkIsPossible(userInput[babyIndex], x)){
                canBeBaby = false;
                break;
            }
            babyIndex++;
        }
        if(canBeBaby){
            cout<<"Possible baby."<<endl;
        } else{
            cout<<"Not their baby!"<<endl;
        }
    }
}
