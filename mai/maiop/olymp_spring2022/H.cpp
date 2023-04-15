#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

struct Path {
    ll v, w;
};

using Graph = vector<vector<Path>>;

bool operator<(const Path& l, const Path& r) {
    return r.w < l.w;
}

void solve() {
    ll n, m, k, md;
    cin >> n >> m >> k >> md;

    priority_queue<Path> q;
    vector<ll> d(n, LLONG_MAX / 100);
    for (int i = 0; i < k; ++i) {
        ll u;
        cin >> u;

        --u;

        q.push({u, 0});
        d[u] = 0;
    }

    Graph g(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        g[v].push_back({u, w});
    }

    vector<int> used(n);

    while (!q.empty()) {
        auto [u, curr_d] = q.top();
        q.pop();

        if (used[u]) {
            continue;
        }
        used[u] = 1;

        for (auto [v, w] : g[u]) {
            if (d[v] > curr_d + w) {
                d[v] = curr_d + w;
                q.push({v, d[v]});
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        if (d[u] <= md) {
            cout << u + 1 << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
