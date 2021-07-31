#include <bits/stdc++.h>

using namespace std;

void solve() {
    unsigned long long n;
    std::cin >> n;
    std::cout << ((n<6) ? 15 : ((n + (n&1)) / 2ull) * 5ull) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
