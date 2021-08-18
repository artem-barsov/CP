#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    std::cin >> k;
    for (int i = 1;; i++) {
        if (i % 3 == 0 || i % 10 == 3) continue;
        if (!--k) {
            std::cout << i << '\n';
            return;
        }
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
