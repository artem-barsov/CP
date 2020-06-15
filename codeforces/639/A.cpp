#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if ((n == 1) || (m == 1) || (n == 2)&&(m == 2))
        std::cout << "YES" << '\n';
    else
        std::cout << "NO" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
