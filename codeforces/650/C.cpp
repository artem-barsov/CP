#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    s = std::string(k, '0') + s + std::string(k, '0') + '1';
    int dist = 0, c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            c += max(0, dist-k) / (k+1);
            dist = -1;
        }
        dist++;
    }
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
