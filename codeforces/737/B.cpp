#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> s = a;
    sort(s.begin(), s.end());
    int c = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) continue;
        auto up = upper_bound(s.begin(), s.end(), a[i-1]);
        c += (up == s.end() || a[i] != *up);
    }
    std::cout << (c < k ? "Yes" : "No") << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
