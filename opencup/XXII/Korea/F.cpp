#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

struct Edge { ll to, w; };

using Graph = vector<vector<Edge>>;

ll dfs(Graph& g, vector<ll>& d, vector<bool>& used, ll u, ll curr = 0) {
    used[u] = true;
    ll ans = 0;
    d[u] = curr;
    for (auto [to, w] : g[u]) {
        if (!used[to] && g[to].size() > 1) {
            ans += 2 * w;
            ans += dfs(g, d, used, to, curr + w);
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> distances(n, INT_MAX);
    vector<bool> used(n, 0);
    ll ans = dfs(g, distances, used, 0);
    ll m = ans;
    for (auto v : distances) {
        if (v != INT_MAX) m = min(m, ans - v);
    }
    cout << m << '\n';
}
