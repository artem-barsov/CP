#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, n, m;
    std::cin >> x >> n >> m;
    while (n-- && (x > 20)) x = x/2 + 10;
    std::cout << (x-m*10 > 0 ? "NO" : "YES") << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
