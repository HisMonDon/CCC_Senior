#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> isprime(2000000, true);
    isprime[0] = isprime[1] = false;

    for (int x = 2; x * x < 2000000; x++) {
        if (isprime[x]) {
            for (int y = x * x; y < 2000000; y += x) {
                isprime[y] = false;
            }
        }
    }

    int T;
    int times;
    cin >> times;
    for (int _ = 0; _ < times; _++) {
        cin >> T;
        for (int count = 0; ; count++) {
            int low = T - count;
            int high = T + count;
            if (low >= 2 && high < 2000000 && isprime[low] && isprime[high]) {
                cout << low << " " << high << endl;
                break;
            }
        }
    }
}
