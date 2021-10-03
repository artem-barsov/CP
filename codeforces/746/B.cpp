#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    if (x <= n / 2) {
        std::cout << "YES" << '\n';
        return;
    }
    std::vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = n - x; i < x; i++) {
        if (a[i] != b[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    std::cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
