#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    if (n%3 == 0) {
        std::cout << n/3  << ' ' << n/3 << '\n';
    }
    else if (n%3 == 1) {
        std::cout << n/3 + 1 << ' ' << n/3 << '\n';
    }
    else if (n%3 == 2) {
        std::cout << n/3 << ' ' << n/3 + 1 << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
