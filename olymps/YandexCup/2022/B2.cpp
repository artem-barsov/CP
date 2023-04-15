#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll calc(string s, ll b) {
    if (s.size() == 0) return 1;
    ll ans = 0;
    ll d = s[0] - '0';
    ll oks = (10 + b - 1) / b;
    for (ll x = 0; x <= d; x += b) {
        if (x == d) ans += calc(s.substr(1), b);
        else if (s.size() != 1) {
            ll p = 1;
            for (int i = 0; i < s.size() - 1; i++) p *= oks;
            ans += p;
        }
        else ans++;
    }
    return ans;
}

void solve() {
    ll n, b;
    cin >> n >> b;
    string sn = to_string(n);
    ll ans = calc(sn, b) - 1;
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