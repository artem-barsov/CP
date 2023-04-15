#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

std::vector<int> tin;
std::vector<int> tout;
std::vector<int> parent;

int dfs(std::vector<std::vector<int> >& gra, int u, int from, int t) {
    parent[u] = from;
    tin[u] = t;
    for (int v : gra[u]) {
        if (v == from) continue;
        t = dfs(gra, v, u, t + 1);
    }
    return tout[u] = t + 1;
}

bool isAncestor_Uv(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA_binlift(std::vector<std::vector<int> >& up, int u, int v) {
    if (isAncestor_Uv(u, v)) return u;
    if (isAncestor_Uv(v, u)) return v;
    for (int l = up[0].size() - 1; l >= 0; l--) {
        if (!isAncestor_Uv(up[u][l], v))
            u = up[u][l];
    }
    return parent[u];
}

int dist(std::vector<std::vector<int> >& up, int u, int v) {
    int du = -isAncestor_Uv(u, v);
    int dv = -isAncestor_Uv(v, u);
    for (int l = up[0].size() - 1; l >= 0; l--) {
        if (!isAncestor_Uv(up[u][l], v)) {
            u = up[u][l];
            du += (1 << l);
        }
        if (!isAncestor_Uv(up[v][l], u)) {
            v = up[v][l];
            dv += (1 << l);
        }
    }
    return du + dv + 2;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > gra(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    tin.resize(n); tout.resize(n); parent.resize(n);
    dfs(gra, 0, 0, 0);
    std::vector<std::vector<int> > up(n, std::vector<int>(bit_width((unsigned)n)));
    for (int v = 0; v < n; v++)
        up[v][0] = parent[v];
    for (int l = 1; l < up[0].size(); l++)
        for (int v = 0; v < n; v++)
            up[v][l] = up[up[v][l-1]][l-1];
    int m;
    std::cin >> m;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        std::cout << dist(up, a, b) << '\n';
    }
}
