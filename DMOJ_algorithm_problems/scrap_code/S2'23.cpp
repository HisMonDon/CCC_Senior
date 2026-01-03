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
    int N;
    cin>> N;
    int i;
    //classic prefix and suffix sum array problem?
    vector<int> v;
    vector<int> psa = {0};
    vector<int> sfa;
    for(int x = 0; x < N; x++){
        cin>>i;
        v.push_back(i);
    }
    for(int x = 0; x < N; x++){
        if(x == 0){
            psa.push_back(v[x]);
            sfa.push_back(v[N - 1]);
        }
        else{
            psa.push_back(psa[x] + v[x]);
            sfa.push_back(sfa[x - 1] + v[N - 1 - x]);
        }
    }
    sfa.push_back(sfa.back());
    /*for(int x : sfa){
        cout<<x<<", ";
    }*/
    for(int _ = 1; _ <= N; _++){
        int m = INT_MAX;
        int s;
        for(int x = 0; x < N - _ + 1; x++){
            s = abs((psa[x + ceil(_/2)] - psa[x]) - (psa[x + _ ] - psa[x + _ - ceil(_/2)]));
            if(s < m){
                if(s == 1) cout<<endl<<_<<" - "<< x <<endl;
                m = s;
            }
        }
        cout<<m<<" ";
    }
}

