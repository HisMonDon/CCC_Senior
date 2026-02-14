#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b; cin>>a>>b; string i;
    vector<int>freq(26, 0);
    bool counter = false; bool prevcounter = true;
    for(int _ = 0; _ < a; _++){
        freq.clear(); freq.shrink_to_fit();
        for(int x = 0; x < 26; x++){freq.push_back(0);} cin>>i;
        for(char x : i){freq[x - 97] ++;}
        for(int x = 0; x < i.size(); x++){
            if(freq[i[x] - 97] >= 2){
                if(x == 0){prevcounter = false;}
                counter = true;
            } else{
                if(x == 0){prevcounter = true;}
                counter = false;
            }
            if(counter == prevcounter){cout<<"F\n"; break;}
            prevcounter = counter;
            if(x == i.size() - 1){cout<<"T\n";}
        }
    }
}
