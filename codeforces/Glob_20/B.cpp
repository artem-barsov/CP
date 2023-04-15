#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    if (s.back() != 'B') {
        std::cout << "NO" << '\n';
        return;
    }
    int a = 0, b = 0;
    for (char c : s) {
        if (c == 'A') a++;
        else          b++;
        if (a < b) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    std::cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
