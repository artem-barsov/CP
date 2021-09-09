#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    bool diffrnt = false;
    int i = 0;
    for (; i < n-1; i++) {
        if (s[i] != s[i+1]) {
            diffrnt = true;
            break;
        }
    }
    if (!diffrnt || n == 1) {
        std::cout << "-1 -1" << '\n';
    } else {
        std::cout << i+1 << ' ' << i + 2 << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
