#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    bool all_ok = true;
    for (int i = 0; i < n; i++) {
        if (c != s[i]) {
            all_ok = false;
            break;
        }
    }
    if (all_ok) {
        std::cout << 0 << '\n';
        return;
    }
    for (int i = n/2; i < n; i++) {
        if (s[i] == c) {
            std::cout << 1 << '\n';
            std::cout << i+1 << '\n';
            return;
        }
    }
    std::cout << 2 << '\n';
    std::cout << n-1 << ' ' << n << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
