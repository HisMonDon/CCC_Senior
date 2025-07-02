#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool checkleft(int x, int y, vector <vector<string>> spirals){

    if(spirals[x][y-1] != " "){
        return true;
    }
    return false;
}
bool checkright(int x, int y, vector <vector<string>> spirals){
    if(spirals[x][y+1] != " "){
        return true;
    }
    return false;
} // if you check left you reach top, else if you check right, you reach bottom
bool checkabove(int x, int y, vector <vector<string>> spirals){
    if(spirals[x-1][y] != " "){
        return true;
    }
    return false;
}
bool checkbelow(int x, int y, vector <vector<string>> spirals){
    if(spirals[x+1][y] != " "){
        return true;
    }
    return false;
} 
void printthing(vector<vector<string>> spirals){
    for (vector<string> i : spirals){
        for(string mystring : i){
            cout<<mystring<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int min;
    int max;
    cin>>min;
    cin>>max;
    int diff = max-min-4;
    int squarenumber = 1;
    while(diff >= 0){
        squarenumber ++; 
        diff -= 8 * (squarenumber - 1);
    }
    string direction = "left";
    squarenumber *= 3;
    int x = squarenumber/2 -1;
    int y = squarenumber/2 -1;
    vector <vector<string>> spirals (squarenumber, vector<string>(squarenumber, " "));
    //spirals[x][y] = to_string(min);
    for(int count = min; count <= max ; count++){
        spirals[x][y] = to_string(count);
        if(direction == "right"){
            if(checkabove(x, y, spirals)){//put parameters when get back
                y++;
            } else{
                direction = "up";
                x--;
            } 
        }
        else if(direction == "left"){
            if(checkbelow(x, y, spirals)){
                y--;
                //chain = false;
            } else {
                direction = "down";
                x++;  
            }
        }
        else if (direction == "down"){
            if (checkright(x, y, spirals)){
                x++;
                //chain = false;
            } else{
                direction = "right";
                y++;           
            }
        }
        else if (direction == "up"){
            if(checkleft(x, y, spirals)){
                x--;
                //chain = false;
            }else{
                direction = "left";
                y--;              
            }
        }
    }
    printthing(spirals);
    
    return 0;
}
