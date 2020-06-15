#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sum += a;
    }
    std::cout << min(m, sum) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve();
}
