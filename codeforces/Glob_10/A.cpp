#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool dif = false;
    std::cin >> a[0];
    for (int i = 1; i < n; i++) {
        std::cin >> a[i];
        dif |= (a[i] != a[i-1]);
    }
    if (dif)
        std::cout << 1 << '\n';
    else
        std::cout << n << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
