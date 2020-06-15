#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    int a = ((1<<n) + ((1<<(n/2)) - 2));
    int b = 2*((1<<(n-1)) - 1) - (a - (1<<n));
    std::cout << a - b << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
