#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

void solve() {
    ull a, b, n, m;
    std::cin >> a >> b >> n >> m;
    if ((a+b >= n+m) && (min(a, b) >= m))
        std::cout << "Yes" << '\n';
    else
        std::cout << "No" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
