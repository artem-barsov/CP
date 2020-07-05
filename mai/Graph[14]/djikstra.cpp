#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, w;
};

int main(int argc, char const *argv[]) {
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;
    std::vector<std::vector<Edge> > edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back(Edge{v, w});
        edges[v].push_back(Edge{u, w});
    }
    std::vector<int> distances(n, inf);
    std::vector<int> relaxed(n);
    distances[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!relaxed[j] && (u == -1) || (distances[j]<distances[u])) {
                u = j;
            }
        } relaxed[u] = 1;
        for (const Edge& e : edges[u]) {
            if (distances[e.to] > distances[u] + e.w) {
                distances[e.to] = distances[u] + e.w;
            }
        }
    }
}
