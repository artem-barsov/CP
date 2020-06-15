#include <bits/stdc++.h>
#define ull unsigned long long
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Priority {
    ull distance, vertex;
};
bool operator < (const Priority &lhs, const Priority &rhs) {
    return lhs.distance < rhs.distance;
}

struct Edge {
    ull to, w;
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n, m, s;
    std::cin >> n >> m >> s;
    s--;
    std::vector<std::vector<Edge> > edges(n);
    for (ull i = 0; i < m; i++) {
        ull u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back(Edge{v, w});
        edges[v].push_back(Edge{u, w});
    }
    std::vector<ull> kapazitat(n, 0);
    std::vector<ull> relaxed(n);
    kapazitat[s] = -1;
    priority_queue<Priority> pq;
    pq.push(Priority{0, s});
    while (!pq.empty()) {
        Priority u = pq.top();
        pq.pop();
        if (relaxed[u.vertex]) continue;
        relaxed[u.vertex] = 1;
        for (const Edge& e : edges[u.vertex]) {
            if (kapazitat[e.to] < min(kapazitat[u.vertex], e.w)) {
                kapazitat[e.to] = min(kapazitat[u.vertex], e.w);
                pq.push(Priority{kapazitat[e.to], e.to});
            }
        }
    }
    for (ull i = 0; i < n; i++) {
        if (kapazitat[i] != -1ull) std::cout << kapazitat[i] << ' ';
        else std::cout << -1 << ' ';
        // std::cout << kapazitat[i] << '\n';
    }
}
