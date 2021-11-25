#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n), pos(n);
    for (auto& x : b) {
        std::cin >> x; x--;
    }
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p; p--;
        pos[p] = i;
    }
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        w[i] = pos[i] - pos[b[i]];
        if (w[i] < 0) {
            std::cout << -1 << '\n';
            return;
        }
    }
    for (auto& x : w) std::cout << x << ' ';
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
