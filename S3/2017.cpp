#include <bits/stdc++.h>
using namespace std;
vector<int> freq(2002, 0);
int getNumOfPossibilities1(int index){
    //int goal = index + 1;
    int count = 0;
    int lo = index;
    int hi;
    hi = index + 1;
    if(min(freq[lo], freq[hi]) >= 1){
        count += min(freq[lo], freq[hi]);
    }
    for(int x = 0; x < 1000; x++){
        lo --; hi++;
        if(lo < 0 || hi > 2000){
            break;
        }
        if(min(freq[lo], freq[hi]) >= 1){
            count += min(freq[lo], freq[hi]);
        }
    }
    return count;
}
int getNumOfPossibilities2(int index){
    //int goal = index + 1;
    int lo = index;
    int hi = index;
    int count = freq[index] / 2;
    for(int x = 0; x < 1000; x++){
        lo --; hi++;
        if(lo < 0 || hi > 2000){
            break;
        }
        if(min(freq[lo], freq[hi]) >= 1){
            count += min(freq[lo], freq[hi]);
        }
    }
    return count;
}
int main(){
    int max = -1;
    int count = 0;
    ios::sync_with_stdio(0);
    cin.tie();
    int n, i, potential; cin >> n;
    for(int x = 0; x < n; x++){
        cin>>i; freq[i]++;
    }
    for(int x = 1; x <= 2000; x++){
        potential = getNumOfPossibilities1(x);
        /*if(potential == 2){
            cout<<"x: "<<x<<", max:"<<max<<endl;
        }*/
        if(potential == max){
            count ++;
        }
        if(potential > max){
            count = 1;
            max = potential;
        }
        potential = getNumOfPossibilities2(x);
        if(potential == max){
            count ++;
        }
        if(potential > max){
            count = 1;
            max = potential;
        }
    }
    cout<<max<<" "<<count;
}
