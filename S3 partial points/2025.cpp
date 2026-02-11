#include <bits/stdc++.h>;
using namespace std;
multiset<int> S;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c, q; cin>>n>>c>>q;
    vector<int>pens(n);
    for(int x = 0; x < n; x++){
        int inpu, inpu2;
        cin>>inpu2>>inpu;
        pens[x] = inpu;
        S.insert(inpu);
    }
    int order, i, p;
    order = -1;
    for(int x = 0; x < q + 1; x++){
      //  copy.clear(); copy.shrink_to_fit(); //copy = pens;
        if(x != 0){cin>>order>>i>>p;}
        if(order == 2){
            S.erase(S.find(pens[i - 1]));
            pens[i-1] = p;
            S.insert(p);
        }
       // sort(copy.begin(), copy.end(), [](vector<int>&a, vector<int>&b){return a[1] > b[1];});
        cout<<*prev(S.end())<<"\n";
    }
}
