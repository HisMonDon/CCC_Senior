#include <bits/stdc++.h>
using namespace std;
int m = INT_MAX;
int total = 0;
int ap, bp, cp, dp;
vector<vector<int>> taken;
void getTotalMoney(int count, int numToSubtract, int num, int a, int b, int c, int d){
    numToSubtract -= num;
    if(numToSubtract == 0){
        vector<int>y = {a, b, c, d};
        for(vector<int> x : taken){
            if(x == y){
                return;
            }
        }
        taken.push_back(y);
        if(count < m){
            m = count;
        }
        total++;
        cout<<"# of PINK is "<<a<<" # of GREEN is "<<b<<" # of RED is "<<c<<" # of ORANGE is "<<d<<"\n";
        return;
    }
    if(numToSubtract <= 0){return;}
    getTotalMoney(count + 1, numToSubtract, ap, a+1, b, c, d);
    getTotalMoney(count + 1, numToSubtract, bp, a, b+1, c, d);
    getTotalMoney(count + 1, numToSubtract, cp, a, b, c+1, d);
    getTotalMoney(count + 1, numToSubtract, dp, a, b, c, d+1);
}
int main(){
    vector<int> colors; int i;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>ap>>bp>>cp>>dp;
    int num; cin >> num;
    getTotalMoney(1, num, ap, 1, 0, 0, 0);
    getTotalMoney(1, num, bp, 0, 1, 0, 0);
    getTotalMoney(1, num, cp, 0, 0, 1, 0);
    getTotalMoney(1, num, dp, 0, 0, 0, 1);
    cout<<"Total combinations is "<<total<<".\nMinimum number of tickets to print is "<<m<<".";
}
