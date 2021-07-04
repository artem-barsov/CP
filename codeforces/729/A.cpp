#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    int c = 0;
    for (size_t i = 0; i < 2*n; i++) {
        int a;
        std::cin >> a;
        c += (a&1);
    }
    std::cout << (c==n ? "Yes" : "No") << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
