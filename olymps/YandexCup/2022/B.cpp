#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// using ull = unsigned ll;
using Graph = vector<vector<int>>;

ll mpow(ll n, ll k) {
    ll p = 1;
    for (ll i = 0; i < k; ++i) p *= n;
    return p;
}

ll solve(string s, ll b) {
    if (s.size() == 0) return 1;
    ll ans = 0;

    ll d = s[0] - '0';

    ll oks = (10 + b - 1) / b;
    for (ll x = 0; x <= d; x += b) {
        if (x == d) {
            ans += solve(s.substr(1), b);
        } else {
            if (s.size() != 1)
                ans += (oks)*mpow(oks, s.size() - 2);
            else
                ++ans;
        }
    }
    return ans;
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        ll n, b;
        cin >> n >> b;

        cout << solve(to_string(n), b) - 1 << '\n';
    }

    return 0;
}