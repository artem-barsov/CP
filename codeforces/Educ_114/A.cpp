#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) std::cout << '(';
        for (int j = 0; j < i  ; j++) std::cout << ')';
        std::cout << '(';
        for (int j = 0; j < n-i; j++) std::cout << ')';
        std::cout << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
