#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

void solve() {
    int n, p, q;
    std::cin >> n >> p >> q;
    p = (p % q) * 10;
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p / q;
        p = (p % q) * 10;
    }
    std::cout << sum << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
