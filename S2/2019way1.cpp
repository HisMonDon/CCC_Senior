#include <bits/stdc++.h>
using namespace std;
int getPrimeNumber(vector<int>&v, int numinline){
    if(v.size() >= numinline){
        return v[numinline-1];
    }
    if(v.size() == 0){
        v.push_back(2);
    }
    int recentnum = v.back() + 1;
    int range = numinline - v.size();
    bool isprime = true;
    for(int x = 0; x < range + 1; x++){
        while(true){
            for(int y = 0 ; y < v.size(); y++){
                if(recentnum % v[y] == 0){
                    isprime = false;
                    break;
                }
            }
            if(isprime){
                v.push_back(recentnum);
            } else {
                x -= 1;
            }
            recentnum ++;
            isprime = true;
            break;
        }
    }
    return v[numinline-1];
}
int main(){
    vector<int> primenumbers;
    int T;
    int skib = 100;
    int temporaryholder;
    int times;
    cin>>times;
    for(int _ = 0; _ < times; _++){
        cin>>T;
        temporaryholder = getPrimeNumber(primenumbers, T*2); // i know i can use void for the function instead of using this variably but just in case something goes wrong ill keep it as it
        for(int count = 0; count <= times; count++){
            if(std::count(primenumbers.begin(), primenumbers.end(), T-count) > 0 && std::count(primenumbers.begin(), primenumbers.end(), T+count) > 0){
                cout<<T-count<<" "<< T+count<<endl;
                break;
            } 
        }
       // cout<<"done"<<endl;

    }
}
