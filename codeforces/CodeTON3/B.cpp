#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s += '$';
    ll x = 0, m = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') x++;
        t++;
        if (s[i] != s[i+1]) {
            m = max(m, t);
            t = 0;
        }
    }
    cout << max(x*(n-x), m*m) << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}