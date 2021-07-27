#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s;
    t = s;
    sort(s.begin(), s.end());
    int c = 0;
    for (size_t i = 0; i < n; i++) {
        c += s[i] != t[i];
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
