#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &v : a) {
        cin >> v;
    }

    vector<ll> l(n, -1), r(n, -1);
    for (int i = 0; i < m; ++i) {
        ll u, lx, rx;
        cin >> u >> lx >> rx;
        --u, --lx, --rx;

        l[u] = lx;
        r[u] = rx;
    }

    multiset<ll> paths;
    vector<vector<ll>> acc(n + 1);

    vector<ll> dp(n, -1);

    auto tear = [&](ll u) {
        for (auto v : acc[u]) {
            if (v < 0) {
                auto it = paths.find(-v);
                if (it != paths.end()) paths.erase(it);
            }
            if (v > 0) {
                paths.insert(v);
            }
        }
    };
    auto push = [&](ll u) {
        if (l[u] == -1) return;
        if (u < 0 || u >= l.size()) {
            cout << "No";
            exit(0);
        }

        ll v = dp[u];
        if (l[u] < 0 || l[u] >= acc.size()) {
            cout << "No";
            exit(0);
        }
        acc[l[u]].push_back(v);
        if (r[u] < 0 || r[u] >= acc.size()) {
            cout << "No";
            exit(0);
        }
        acc[r[u] + 1].push_back(-v);
    };

    dp[0] = a[0];
    push(0);

    for (ll u = 1; u < n; ++u) {
        tear(u);

        auto p = paths.rbegin();
        if (p == paths.rend()) continue;

        dp[u] = a[u] + *p;
        push(u);
    }

    ll ans = dp[n - 1];
    if (ans != -1) {
        cout << ans << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
