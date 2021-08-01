#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9;

void solve() {
    int n, m;
    std::cin >> n >> m;
    m++;
    int x = 0;
    for (int i = ceil(log2(MAXN)); (n^x) < m && i >= 0; i--) {
        if ((n & (1<<i)) < (m & (1<<i)))
            x |= (1 << i);
    }
    std::cout << x << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
