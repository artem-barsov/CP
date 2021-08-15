#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int idx0 = n-1;
    while (idx0 >= 0 && a[idx0] == 1) idx0--;
    for (int i = 0; i <= idx0; i++)
        std::cout << i+1 << ' ';
    std::cout << n+1 << ' ';
    for (int i = idx0+1; i < n; i++)
        std::cout << i+1 << ' ';
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
