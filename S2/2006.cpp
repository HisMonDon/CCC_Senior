#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>

using namespace std;

char findchar(vector<char> good, vector<char> cipher, char wanted, int size){
    for(int x = 0; x < size; x++){
        if (cipher[x] == wanted){
            return good[x];
        }
    }
    return '.';
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<char> goodtext;
    vector<char> ciphertext;
    vector<char> remainingchars = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    vector<char> remaininggibberish = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    vector<vector<char>> discovered;
    string goodtextstring;
    string ciphertextstring;
    string gibberish;
    string finalstring = "";
    getline(cin, goodtextstring);
    getline(cin, ciphertextstring);
    int size = goodtextstring.size();
    
    for (int x = 0; x < size; x++){
        goodtext.push_back(goodtextstring[x]);
        ciphertext.push_back(ciphertextstring[x]);
    }
    getline(cin, gibberish);
    for(char x : goodtext){
        for(int z = 0; z <= remainingchars.size(); z++){
            if(remainingchars[z] == x){
                remainingchars.erase(remainingchars.begin() + z);
                break;
            }
        }
    }
    /*for(char x : remaininggibberish){
        cout<<x<<",";
    }*/
    for(char x : gibberish){
        char newchar = findchar(goodtext, ciphertext, x ,size);
        if(newchar == '.' && remainingchars.size() == 1){
            newchar = remainingchars[0];
        }
        finalstring += newchar;
    }
    cout<<finalstring<<endl;
   /* for (char x : remaininggibberish){
        cout<<x;
    }*/

}
