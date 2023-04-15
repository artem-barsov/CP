#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n = 1;
    // cin >> n;
    vector<ll> a(n);
    // for (auto&& x : a) cin >> x;
    vector<ll> ps(n);
    inclusive_scan(a.begin(), a.end(), ps.begin());
    ll ans = 0, i = 0;
    for (; i < n; i++) {
        if (a[i] == 0) break;
        if (ps[i] == 0) ans++;
    }
    map<ll, ll> num_cnt;
    ll fr = 0;
    for (; i < n; i++) {
        if (a[i] == 0) {
            ans += fr;
            fr = 0;
            num_cnt.clear();
        }
        fr = max(fr, ++num_cnt[ps[i]]);
    }
    ans += fr;
    cout << ans << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
}