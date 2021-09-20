#include <bits/stdc++.h>

using namespace std;

void solve() {
    std::vector<int> a(3);
    for (auto& x : a) std::cin >> x;
    int m;
    std::cin >> m;
    sort(a.begin(), a.end());
    int l = a[2] - a[1] - a[0] - 1;
    int r = a[0] + a[1] + a[2] - 3;
    std::cout << ((l <= m&&m <= r) ? "YES" : "NO") << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
