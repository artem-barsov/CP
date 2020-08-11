#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void solve() {
    ull x, y, a, b;
    std::cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    if (b <= 2*a)
        std::cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << '\n';
    else
        std::cout << a * (x + y) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
