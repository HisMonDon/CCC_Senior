#include <iostream>
#include <cstdlib>
using namespace std;
bool First(int numPlayed) {
    if(numPlayed == 35) {
        return true;
    }
    return false;
}
bool Second(int numPlayed) {
    if(numPlayed == 100) {
        return true;
    }
    return false;
}
bool Third(int numPlayed) {
    if(numPlayed == 10) {
        return true;
    }
    return false;
}
bool check(int x) {
    if(x <1) {
        return true;
    }
    return false;
}
int main() {
    int numtimes = 0;
    int qRemaining;
    int first;
    int second;
    int third;
    cin>>qRemaining;
    cin>>first;
    cin>>second;
    cin>>third;
    while(qRemaining>0) {
        qRemaining--;
        first ++;
        if(First(first)) {
            first = 0;
            qRemaining += 30;
        }
        numtimes++;
        qRemaining--;
        second ++;
        if(check(qRemaining)) {
            break;
        }
        if(Second(second)) {
            second = 0;
            qRemaining += 60;
        }
        numtimes++;
        qRemaining--;
        third ++;
        if(check(qRemaining)) {
            break;
        }
        if(Third(third)) {
            third = 0;
            qRemaining += 9;
        }
        numtimes++;
        if(check(qRemaining)) {
            break;
        }

    }
    cout<< "Martha plays " <<numtimes+1<< " times before going broke.";
}
