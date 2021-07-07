#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    long long sum_a = 0;
    for (size_t i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sum_a += a;
    }
    int part = sum_a % n;
    std::cout << part *1ull* (n-part) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
