#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int c = 0;
    std::string s;
    for (int i = 0; i < n-1; i++) {
        std::cin >> s;
        c += s.back() == 'R';
    }
    std::cin >> s;
    for (int i = 0; i < m; i++) {
        c += (s[i] == 'D');
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
