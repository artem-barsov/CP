#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;

ll sum(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

ll f(ll k) {
    if (k == 0) return (1 + n) * n / 2;
    ll g = (n + k) / (k + 1);
    ll gl = g * (k + 1) - n;
    ll gh = k + 1 - gl;
    return gl * sum(1, g - 1) + gh * sum(1, g) + k * m;
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif
    cin >> n >> m;
    ll l = 0, r = n;
    while (r - l >= 3) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    ll ans = LLONG_MAX;
    for (ll x = l; x <= r; ++x) {
        ans = min(ans, f(x));
    }
    cout << ans << '\n';
}