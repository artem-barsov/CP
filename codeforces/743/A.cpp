#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            c += s[i]-'0' + !!(n-i-1);
        }
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
