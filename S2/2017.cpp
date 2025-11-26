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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lowCount = ceil(n/2.0);
    int highCount = n - lowCount;
   /* for(int x : a){
      cout<<x<<" ";
    } cout<<endl;*/
    vector<int> low(a.begin(), a.begin() + lowCount);
    vector<int> high(a.begin() + lowCount, a.end());
    reverse(low.begin(), low.end());

    for (int i = 0; i < n - lowCount; i++) {
        cout << low[i] << " " << high[i] << " ";
    }
    if (lowCount > highCount){
      cout << low.back();
    }
}
