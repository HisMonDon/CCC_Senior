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
    int numOfEps, Q;
    vector<int> ps;
    vector<int> sf;
    vector<int> individualRatings;
    cin>>numOfEps>>Q;
    string epRating;
    cin.ignore();
    getline(cin, epRating);
    stringstream ss(epRating);
    int r;
    bool first = true;
    ps.push_back(0);
    while(ss >> r){
        individualRatings.push_back(r);
        if(first){
            first = false;
            ps.push_back(r);
        } else {
            ps.push_back(ps.back() + r);
        }
    }
    sf.push_back(individualRatings.back());
    for(int x = individualRatings.size() - 2; x > -1; x--){
        sf.push_back(sf.back() + individualRatings[x]);
    }
    //sf.push_back(0);
    for(int _ = 0; _ < Q; _++){
        int start, end;
        cin>>start>>end;
        int sum = 0;
        if(end != individualRatings.size()){
            sum += sf[sf.size() - end - 1];
        }
        sum += ps[start - 1];
        cout<<sum<<endl;
    }


   /* for(int x : sf){
        cout<<x<<", ";
    }
    cout<<endl;
    for(int x : ps){
        cout<<x<<", ";
    }*/
}
