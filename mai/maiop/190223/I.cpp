#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

struct InCycle {
    int cycle_id;
    int pos;
};

struct InChain {
    int chain_id;
    int pos;
};

vector<int> g[2], gr[2];

map<int, InCycle> in_cycle[2];
map<int, InChain> in_chain[2];
map<int, int> chain_to_cycle[2];

vector<vector<int>> cycles[2];
vector<vector<int>> chains[2];

void find_cycles(int u, int c, vector<int>& used) {
    if (used[u] == 2) {
        return;
    }
    if (used[u] == 1) {
        // In cycle.
        int cycle_id = cycles[c].size();
        cycles[c].push_back({});

        bool ok = true;
        for (int uu = u; (uu != u) || ok; uu = g[c][uu]) {
            ok = false;

            int pos = cycles[c][cycle_id].size();
            in_cycle[c][uu] = {cycle_id, pos};
            cycles[c][cycle_id].push_back(uu);
        }
        return;
    }

    used[u] = 1;
    find_cycles(g[c][u], c, used);
    used[u] = 2;
}

void find_chains(int u, int c) {
    if (in_cycle[c].count(u) || in_chain[c].count(u)) {
        return;
    }

    int p = u;
    while (gr[c][p] != -1) {
        p = gr[c][p];
    }

    int chain_id = chains[c].size();
    chains[c].push_back({});
    for (u = p; !in_cycle[c].count(u); u = g[c][u]) {
        int pos = chains[c][chain_id].size();
        chains[c][chain_id].push_back(u);
        in_chain[c][u] = {chain_id, pos};
    }

    chain_to_cycle[c][chain_id] = u;
}

int go(int u, int c, int k) {
    if (in_chain[c].count(u)) {
        auto in = in_chain[c][u];
        int chain_len = chains[c][in.chain_id].size();

        if (k < chain_len - in.pos) {
            int pos = (in.pos) + k;
            return chains[c][in.chain_id][pos];
        } else {
            k -= chain_len - in.pos;
            return go(chain_to_cycle[c][in.chain_id], c, k);
        }
    } else {
        auto in = in_cycle[c][u];
        int cycle_len = cycles[c][in.cycle_id].size();
        int pos = (in.pos + k) % cycle_len;

        return cycles[c][in.cycle_id][pos];
    }
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    g[0].resize(n);
    g[1].resize(n);
    gr[0].resize(n, -1);
    gr[1].resize(n, -1);

    for (int u = 0; u < n; ++u) {
        int v;
        cin >> v;
        --v;
        g[0][u] = v;
        gr[0][v] = u;
    }
    for (int u = 0; u < n; ++u) {
        int v;
        cin >> v;
        --v;
        g[1][u] = v;
        gr[1][v] = u;
    }

    vector<int> used_0(n), used_1(n);
    for (int u = 0; u < n; ++u) {
        find_cycles(u, 0, used_0);
        find_cycles(u, 1, used_1);
    }
    for (int u = 0; u < n; ++u) {
        find_chains(u, 0);
        find_chains(u, 1);
    }

    for (int i = 0; i < q; ++i) {
        int x, a, b, c;
        cin >> x >> a >> b >> c;
        --x;

        int res;
        if (c == 0) {
            res = go(x, 0, a);
            res = go(res, 1, b);
        } else {
            res = go(x, 1, b);
            res = go(res, 0, a);
        }
        cout << res + 1 << '\n';
    }

    return 0;
}