#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (auto& x : p) std::cin >> x;
    if (p.front() != n && p.back() != n) {
        std::cout << -1 << '\n';
        return;
    }
    std::cout << n << ' ';
    if (p.front() == n) {
        for (int i = n-1; i >= 1; i--)
            std::cout << p[i] << ' ';
    }
    else {
        for (int i = n-2; i >= 0; i--)
            std::cout << p[i] << ' ';
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
