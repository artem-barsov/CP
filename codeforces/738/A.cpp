#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ans;
    std::cin >> n >> ans;
    for (int i = 0; i < n-1; i++) {
        int a;
        std::cin >> a;
        ans &= a;
    }
    std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
