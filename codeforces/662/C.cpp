#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    map<int, int> a;
    int mn = 0, ma = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        a[ai]++;
        if (a[ai] == ma) mn++;
        else if (a[ai] > ma) {
            ma = a[ai];
            mn = 1;
        }
    }
    std::cout << (n-mn)/(ma-1) - 1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
