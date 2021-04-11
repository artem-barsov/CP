#include <bits/stdc++.h>

using namespace std;

struct Priority {
    int distance, vertex;
};
bool operator < (const Priority &lhs, const Priority &rhs) {
    return lhs.distance > rhs.distance;
}

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
    priority_queue<Priority> pq;
    pq.push(Priority{0, s});
    while (!pq.empty()) {
        Priority u = pq.top();
        pq.pop();
        if (relaxed[u.vertex]) continue;
        relaxed[u.vertex] = 1;
        for (const Edge& e : edges[u]) {
            if (distances[e.to] > distances[u.vertex] + e.w) {
                distances[e.to] = distances[u.vertex] + e.w;
                pq.push(Priority{distances[e.to], e.to});
            }
        }
    }
}
