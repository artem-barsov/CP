#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

using Graph = vector<vector<int>>;

int n, m;
Graph g;
vector<int> mt;
vector<int> used;

bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    g = Graph(n);

    vector<string> name(n);
    struct Skill {
        string name;
        int skill;
    };
    vector<vector<Skill>> skill(n);

    for (int i = 0; i < n; ++i) {
        cin >> name[i];

        int k;
        cin >> k;

        skill[i].resize(k);
        for (int j = 0; j < k; ++j) {
            string t;
            int s;

            cin >> t >> s;

            skill[i][j] = {t, s};
        }
    }

    cin >> m;
    vector<string> req_name(m);
    vector<int> req_skill(m);

    for (int v = 0; v < m; ++v) {
        string t;
        int s;

        cin >> t >> s;
        req_name[v] = t;
        req_skill[v] = s;

        for (int u = 0; u < n; ++u) {
            for (auto [tt, ss] : skill[u]) {
                if (tt == t && ss >= s) {
                    g[u].push_back(v);
                }
            }
        }
    }

    mt.assign(m, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < m; ++i) {
        if (mt[i] == -1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i)
        cout << req_name[i] << ' ' << req_skill[i] << ' ' << name[mt[i]]
             << '\n';
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
