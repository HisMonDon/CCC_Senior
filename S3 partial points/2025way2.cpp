#include <bits/stdc++.h>;
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int N, M, Q, ci, pi;
    cin>>N>>M>>Q;
    vector<int> pens (N);
    map<int, int> q;
    for(int x = 0; x < N; x++){
        cin>>ci>>pi;
        q[pi]++; pens[x] = pi;
    }

    int a, b, c;
    for(int x = 0; x < Q + 1; x++){
        if(x != 0){
            cin>>a>>b>>c;
            if(a == 2){
                q[pens[b-1]] --;
                if(q[pens[b-1]] <= 0){
                    q.erase(pens[b-1]);
                }
                pens[b - 1] = c;
                q[c] ++;
            }
        }
        cout<<q.rbegin()->first<<"\n";
    }
}
