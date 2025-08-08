#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <climits>
#include <map>
#include <sstream>
using namespace std;
bool isVowel(char letter){
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for(char x : vowels){
        if(x == letter){
            return true;
        }
    }
    return false;
}
string getLastSyllable(string word){
    string ans = "";
    for(int x = word.size() - 1; x >= 0; x --){
        ans += string(1, tolower(word.at(x)));
        if (isVowel(tolower(word.at(x)))){
            return ans;
        }
    }
    return ans;
}
bool compareSyllables(string a, string b){
    if(a == b){
        return true;
    }
    return false;
}
string typeOfRhyme(vector<string> LastSyllable){
    /*cout<<"Last Syllables Vector: \n===========================\n";
    for(string x : LastSyllable){
        cout<<x << " ";
    }
    cout<<"\n";*/
    if(LastSyllable[0] == LastSyllable[1] && LastSyllable[1]== LastSyllable[2] && LastSyllable[2] == LastSyllable[3]){
        return("\nperfect");
    }
    if(LastSyllable[0] == LastSyllable[1] && LastSyllable[2] == LastSyllable[3]){
        return("\neven");
    }
    if(LastSyllable[0] == LastSyllable[2] && LastSyllable[1] == LastSyllable[3]){
        return("\ncross");
    }
    if(LastSyllable[0] == LastSyllable[3] && LastSyllable[1] == LastSyllable[2]){
        return("\nshell");
    }
    return ("\nfree");
}

int main(){
    int numOfPoems;
    cin>>numOfPoems;
    cin.ignore();
    string input;
    vector<string> lastSyllable;
    vector<string> fullSentence;
    for(int _ = 0; _ < numOfPoems; _++){
        for(int x = 0; x < 4; x++){
            getline(cin, input);
            stringstream ss(input);
            string word;
            while(ss >> word){
                fullSentence.push_back(word);
            }
            lastSyllable.push_back(getLastSyllable(fullSentence[fullSentence.size() - 1]));
            fullSentence.clear();
        }
        cout<<typeOfRhyme(lastSyllable);
        lastSyllable.clear();

    }
}
