#include <bits/stdc++.h>;
using namespace std;
vector<int> xorr(vector<int> a, vector<int> b){
    vector<int> v;
    for(int x = 0; x < a.size(); x++){
        if(a[x] == b[x]){v.push_back(0);} else{ v.push_back(1);}
    }
    return v;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int r, l; cin>>r>>l; int n = 0;
    vector<int> p(l);
    vector<vector<int>> taken;
    //vector<vector<int>> grid(r, vector<int>(l));
    vector<vector<int>> grid;
    for(int x = 0; x < r; x++){
        grid.push_back({});
        for(int y = 0; y < l; y++){
            int i;
            cin>>i;
            grid[x].push_back(i);
        }
    }
    taken.push_back(grid[grid.size() - 1]);
    for(int x = r - 1; x >= 0; x--){
        p.clear(); p.shrink_to_fit();
        p = grid[x];
        /*for(int x : p){
            cout<<x<<": ";
        }*/
        for(int y = x + 1; y <= r - 1; y++){
            p = xorr(p, grid[y]);
        }
        bool found = false;
        for(vector<int> x : taken){
            if(p == x){
                //cout<<"wow";
                found = true;
                break;
            }
        }
        if(!found){
            taken.push_back(p);
        }
    }
   /*for(vector<int>x : taken){
        for(int y : x){
            cout<<y<<", ";
        }
        cout<<endl;
    }*/
    cout<<taken.size();
}
