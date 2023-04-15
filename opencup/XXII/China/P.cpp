#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ull n;
    cin >> n;
    // cout << n << '\n';
    vector<char> dig(10, false);
    int cnt = 0;
    ull k = 1;
    for (;; k++) {
        string s = std::to_string(k * n);
        // cout << k << ' ' << n << ' ' << k * n << ' ' << s << " : ";
        for (char ch : s) {
            if (!dig[ch-'0']) {
                dig[ch-'0'] = true;
                cnt++;
                // cout << ch;
            }
        }
        // cout << '\n';
        if (cnt == 10) break;
    }
    cout << k << '\n';
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
/*
21354654326
666666666
*/