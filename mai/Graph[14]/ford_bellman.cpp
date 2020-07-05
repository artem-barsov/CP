#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

int main(int argc, char const *argv[]) {
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    std::vector<int> distances(n, inf);
    std::vector<int> parents(n, -1);
    distances[s] = 0;
    for (int i = 0; i < n; i++) {
        bool changed = false;
        for (const Edge& e : edges) {
            if (distances[e.v] > distances[e.u] + e.w) {
                changed = true;
                distances[e.v] = distances[e.u] + e.w;
                parents[e.v] = e.u;
            }
            if (distances[e.u] > distances[e.v] + e.w) {
                changed = true;
                distances[e.u] = distances[e.v] + e.w;
                // parents[e.v] = e.u; ???????????????
            }
        }
        if (!changed) break;
    }
}
