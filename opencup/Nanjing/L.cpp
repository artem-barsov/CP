#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int a = x2-x1 + x4-x3 - (max(x2,x4)-min(x1,x3));
    int b = y2-y1 + y4-y3 - (max(y2,y4)-min(y1,y3));
    if (((a > 0) && (b > 0)) && !((x1 == x3) && (y1 == y3) && (x2 == x4) && (y2 == y4))) {
        if (x1 == x3) {
            if ((x2-x1)*(y2-y1) < (x4-x3)*(y4-y3)) { // 1 > 2
                swap(x1, x3);
                swap(x2, x4);
                swap(y1, y3);
                swap(y2, y4);
            } // 1 > 2
            if ((x4 <= x2) && (y4 <= y2)) {
                std::cout << 3 << '\n';
            }
        }
        else if (x2 == x4) {
            if ((x2-x1)*(y2-y1) < (x4-x3)*(y4-y3)) { // 1 > 2
                swap(x1, x3);
                swap(x2, x4);
                swap(y1, y3);
                swap(y2, y4);
            } // 1 > 2
            if ((x3 <= x1) && (y3 <= y1)) {
                std::cout << 3 << '\n';
            }
        }
    }
    else std::cout << 2 << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
