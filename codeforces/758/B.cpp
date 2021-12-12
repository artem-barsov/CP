#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (abs(a - b) > 1
     || max(a, b) > (n - 1) / 2
     || min(a, b) > (n - 2) / 2) {
        std::cout << -1 << '\n';
        return;
    }
    int lo = 1, hi = n;
    bool up;
    if (a >= b) {
        std::cout << lo++ << ' ';
        up = true;
    }
    else {
        std::cout << hi-- << ' ';
        up = false;
    }
    while (hi > lo - 1) {
        if (up && a-- > 0) {
            std::cout << hi-- << ' ';
            up = false;
        }
        else if (!up && b-- > 0) {
            std::cout << lo++ << ' ';
            up = true;
        }
        else if (up) std::cout << lo++ << ' ';
        else         std::cout << hi-- << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
