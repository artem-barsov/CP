#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

using Graph = vector<vector<int>>;

void dfs(Graph& g, vector<int>& c, int u, int p = -1) {
    int cc = 0;
    for (auto v : g[u]) {
        if (v == p) continue;

        dfs(g, c, v, u);
        cc += c[v] + 1;
    }

    c[u] = cc;
}

struct Edge {
    int u, v, w;
};

void solve() {
    int n, s;
    cin >> n >> s;
    --s;

    Graph g(n);
    vector<Edge> edges;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v, w});
    }

    vector<int> c(n);
    dfs(g, c, s);

    // cout << "c: ";
    // for (auto v : c) {
    //     cout << v << ' ';
    // }
    // cout << '\n';

    auto priority = [&](const Edge& e) {
        if (max(c[e.u], c[e.v]) / 2 <= min(c[e.u], c[e.v])) {
            return 2 * e.w;
        }
        return e.w;
    };
    sort(edges.begin(), edges.end(), [&](const Edge& l, const Edge& r) {
        return priority(r) < priority(l);
    });

    // cout << "e:\n";
    // for (auto e : edges) {
    //     cout << e.u << ' ' << c[e.u] << ' ' << e.v << ' ' << c[e.v] << ' '
    //          << priority(e) << '\n';
    // }
    // cout << '\n';

    // cout << "ANS:\n";
    for (auto [u, v, w] : edges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
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
