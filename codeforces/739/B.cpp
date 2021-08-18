#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int n = 2 * abs(a - b);
    if (a > n || b > n || c > n)
        std::cout << -1 << '\n';
    else if (c > n/2)
        std::cout << c - n/2 << '\n';
    else
        std::cout << c + n/2 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
