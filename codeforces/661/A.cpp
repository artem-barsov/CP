#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        if (abs(a[i+1] - a[i]) > 1) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    std::cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
