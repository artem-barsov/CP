#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void solve() {
    ull n;
    std::cin >> n;
    ull x, c = 0;
    while (x = (-1 + sqrt(1 + 24*n)) / 6) {
        n -= (3*x*x + x) / 2;
        c++;
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    ull t;
    std::cin >> t;
    while (t--) solve();
}
