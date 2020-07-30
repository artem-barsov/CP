#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    std::cin >> l >> r;
    if (2*l <= r) std::cout << l << ' ' << 2*l << '\n';
    else std::cout << "-1 -1" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
