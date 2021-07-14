#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;
    if (b >= 0) {
        std::cout << n * (a + b) << '\n';
    }
    else {
        bool f = (s[0] == '1');
        int s0 = !f, s1 = f;
        for (size_t i = 0; i < n; i++) {
            if (f && s[i] == '0') {
                f = !f;
                s0++;
            }
            else if (!f && s[i] == '1') {
                f = !f;
                s1++;
            }
        }
        std::cout << a*n + b*(min(s0, s1) + 1) << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
