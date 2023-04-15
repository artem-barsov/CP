#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

using Graph = std::vector<std::vector<int> >;

int dfs(Graph& gra, std::vector<int>& deps, int u, int from) {
    int dep = 0;
    for (int v : gra[u]) {
        if (v == from) continue;
        dep = max(dep, dfs(gra, deps, v, u));
    }
    return deps[u] = dep + 1;
}

int d;
struct Vertex { int deg; bool used; };
std::vector<Vertex> adj;

bool interact() {
    std::string r;
    while (std::cin >> r) {
        if (r == "AC" || r == "F") false;
        std::cin >> d;
        if (d > adj.size()) adj.resize(d);
        for (int i = 0; i < d; i++)
            std::cin >> adj[i].deg >> adj[i].used;
    }
    return true;
}

void short_sub(int idx, int depth) {
    std::cout << idx + 1 << endl;
    interact();
    for (int i = 0; i < d; i++) {
        if (!adj[i].used) {
            short_sub(i, depth+1);
            return;
        }
    }
    
}

void solve() {
    int n, m, start, bmc;
    std::cin >> n >> m >> start >> bmc;
    start--;
    Graph gra(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    std::vector<int> deps(n, -1);
    dfs(gra, deps, start, -1);
    int max_dep = -1, deg_max;
    for (int v : gra[start]) {
        if (max_dep < deps[v]) {
            max_dep = deps[v];
            deg_max = gra[v].size();
        }
    }
// for (int i = 0; i < n; i++) {
// printf("%d: dep = %d, deg = %d\n", i+1, deps[i], gra[i].size());
// }
    if (!interact()) return;
    for (int i = 0; i < d; i++) {
        if (adj[i].deg != deg_max) {
            short_sub(i, 0);
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
