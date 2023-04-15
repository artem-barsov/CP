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
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        map<char, int> dig_used;
        for (int j = 0; j < 100 && i+j < n; j++) {
            dig_used[s[i+j]]++;
            bool ok = true;
            for (auto &&[dig, cnt] : dig_used) {
                if (cnt > dig_used.size()) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << '\n';
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