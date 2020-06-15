#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void solve() {
    ull n;
    std::cin >> n;
    ull x;
    for (ull k = 2; k <= 30; k++) {
        ull t = ((1 << k) - 1);
        x = n / t;
        if ((ull)n == (ull)(x * t)) break;
    }
    std::cout << x << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
