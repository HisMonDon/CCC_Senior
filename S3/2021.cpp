#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> f;
long long check(int index) {
    long long currentTime = 0;
    for (vector<long long> y : f) {
        long long temp = y[1] * (abs(index - y[0]) - y[2]);
        if (temp >= 0) {
            currentTime += temp;
        }
    }
    return currentTime;
}
int isMin(int index) {
    long long a= LONG_LONG_MAX;
    long long c= LONG_LONG_MAX;
    long long b= LONG_LONG_MAX;
    b = check(index);
    if (index > 0) {
        a = check(index - 1);
    }
    c = check(index + 1);
    if (b < a && b < c) {
        return 0;
    }
    if (b >= a) {
        return -1;
    }
    return 1;
}
int main(){
    long long lo, hi;
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, p, w, d;
    cin>>n;
    for (int x = 0; x < n; x++) {
        cin>>p>>w>>d;
        f.push_back({p, w, d});
    }

    lo = 0;
    hi = 999999999;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long step = isMin(mid);
        if (step == 1) {
            lo = mid + 1;
        } else if (step == -1) {
            hi = mid - 1;
        } else {
            cout<<check(mid);
            return 0;
        }
    }
    //cout<<"wtf";

    cout<<check(lo);
}
