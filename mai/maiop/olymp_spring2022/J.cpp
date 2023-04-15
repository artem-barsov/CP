#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

using Graph = vector<vector<int>>;

class DSU {
    vector<int> leader;

public:
    DSU(int n) : leader(n) {
        iota(leader.begin(), leader.end(), 0);
    }

    int find(int u) {
        if (leader[u] == u) {
            return u;
        }
        return leader[u] = find(leader[u]);
    }

    int join(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            leader[u] = v;
            return 1;
        }

        return 0;
    }
};

int n, m, q;

int id(int x, int y) {
    return x * m + y;
}

void solve() {
    cin >> n >> m >> q;

    int ans = 0;
    vector<vector<int>> p(n, vector<int>(m));

    DSU d(n * m);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        --x, --y;
        p[x][y] = 1;

        ++ans;
        int u = id(x, y);

        ans -= x < n - 1 && p[x + 1][y] && d.join(u, id(x + 1, y));
        ans -= x > 0 && p[x - 1][y] && d.join(u, id(x - 1, y));
        ans -= y < m - 1 && p[x][y + 1] && d.join(u, id(x, y + 1));
        ans -= y > 0 && p[x][y - 1] && d.join(u, id(x, y - 1));

        cout << ans << '\n';
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
