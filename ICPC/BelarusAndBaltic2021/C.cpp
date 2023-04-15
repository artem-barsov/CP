#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

int mex(const set<int>& s) {
    for (int n = 0;; ++n) {
        if (!s.count(n)) return n;
    }
}

int dfs(Graph& g, vector<int>& used, vector<int>& f, int u) {
    if (used[u]) return f[u];
    used[u] = 1;

    set<int> s;
    for (auto v : g[u]) {
        s.insert(dfs(g, used, f, v));
    }

    f[u] = mex(s);
    return f[u];
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        --u, --v;

        g[u].push_back(v);
    }

    vector<int> used(n), f(n);
    for (int i = 0; i < n; ++i) {
        dfs(g, used, f, i);
    }

    for (auto v : f) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}
