#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

struct Edge {
    ull u, v, w;
};

int main(int argc, char const *argv[]) {
    ull n, m, s;
    std::cin >> n >> m >> s;
    s--;
    std::vector<Edge> edges(m);
    for (ull i = 0; i < m; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
    }
    std::vector<ull> distances(n, 10000000000);
    distances[s] = 0;
    for (ull i = 1; i < n; i++) {
        bool changed = false;
        for (const Edge& e : edges) {
            if (distances[e.v] > distances[e.u] + e.w) {
                changed = true;
                distances[e.v] = distances[e.u] + e.w;
            }
            if (distances[e.u] > distances[e.v] + e.w) {
                changed = true;
                distances[e.u] = distances[e.v] + e.w;
            }
        }
        if (!changed) break;
    }
    for (ull i = 0; i < n; i++) {
        if (distances[i] < 10000000000) std::cout << distances[i] << ' ';
        else std::cout << -1 << ' ';
    }
}
