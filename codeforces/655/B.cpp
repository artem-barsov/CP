#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    auto upp = sqrt(n);
    for (int i = 2; i <= upp; i++) {
        if (n % i == 0) {
            std::cout << n/i << ' ' << n/i*(i-1) << '\n';
            return;
        }
    }
    std::cout << 1 << ' ' << n-1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
