#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        zeros += (a == 0);
    }
    if (zeros >= n/2) {
        std::cout << n/2 << '\n';
        for (int i = 0; i < n/2; i++)
            std::cout << 0 << ' ';
    }
    else {
        if (n & 2) {
            std::cout << n/2 + 1 << '\n';
            for (int i = 0; i < n/2 + 1; i++)
                std::cout << 1 << ' ';
        }
        else {
            std::cout << n/2 << '\n';
            for (int i = 0; i < n/2; i++)
                std::cout << 1 << ' ';
        }
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
