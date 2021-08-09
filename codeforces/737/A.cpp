#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    int maxa = -1e9 - 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sum += a;
        maxa = max(maxa, a);
    }
    std::cout.precision(20);
    std::cout << double(sum-maxa) / (n-1) + maxa << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
