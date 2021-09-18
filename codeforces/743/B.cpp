#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> pa(2 * n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        pa[a] = i;
    }
    int mdist = INT_MAX;
    int lasta = 1;
    for (int i = 0; i < n; i++) {
        int bi;
        std::cin >> bi;
        for (; lasta < bi; lasta += 2) {
            mdist = min(mdist, pa[lasta] + i);
        }
    }
    std::cout << mdist << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
