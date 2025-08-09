#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <climits>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

int getNumberOfPoints(int r) {
    if (r == 0) {
        return 1;
    }
    int total = 2 * r + 1;
    long long r2 = (long long)r * r;
    for (int x = 1; x <= r; x++) {
        long long x2 = (long long)x * x;
        long long rem = r2 - x2;
        if (rem < 0) {
            break;
        }
        long long low = 0;
        long long high = r;
        int y_max = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long mid2 = mid * mid;
            if (mid2 <= rem) {
                y_max = (int)mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        total += 4 * y_max + 2;
    }
    return total;
}

int main() {
    int r;
    while (true) {
        cin >> r
        if (r == 0) {
            break;
        }
        cout << getNumberOfPoints(r) << endl;
    }
    return 0;
}
