#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, n;
    std::cin >> a >> b >> n;
    int c = 0;
    while ((a <= n) && (b <= n)) {
        if (a < b) a += b;
        else b += a;
        c++;
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
