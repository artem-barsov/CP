#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, r;
    std::cin >> n >> r;
    int x = min(n-1, r);
    std::cout << (unsigned long long)x*(x+1)/2 + (n<=r) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
