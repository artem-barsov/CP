#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    ll ans_ = 0;
    for (ll i = 1; i * i <= k && i <= n; i++) {
        if (k % i == 0 && k / i <= n) {
            if (k / i == i) {
                ans_++;
            } else {
                ans++;
            }
        }
    }

    cout << ans * 2 + ans_ << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}
