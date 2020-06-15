#include <bits/stdc++.h>
#define ull unsigned long long
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Priority {
    ull distance, vertex;
};
bool operator < (const Priority &lhs, const Priority &rhs) {
    return lhs.distance > rhs.distance;
}

struct Edge {
    ull to, w;
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge> > edges(n);
    for (ull i = 0; i < m; i++) {
        ull u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back(Edge{v, w});
        edges[v].push_back(Edge{u, w});
    }
    std::vector<ull> distances(n, 1000000000000000000);
    std::vector<ull> relaxed(n);
    std::vector<int> parents(n, -1);
    distances[0] = 0;
    priority_queue<Priority> pq;
    pq.push(Priority{0, 0});
    while (!pq.empty()) {
        Priority u = pq.top();
        pq.pop();
        if (relaxed[u.vertex]) continue;
        relaxed[u.vertex] = 1;
        for (const Edge& e : edges[u.vertex]) {
            if (distances[e.to] > distances[u.vertex] + e.w) {
                distances[e.to] = distances[u.vertex] + e.w;
                pq.push(Priority{distances[e.to], e.to});
                parents[e.to] = u.vertex;
            }
        }
    }
    std::vector<int> weg;
    weg.push_back(n-1);
    while (weg.back()) {
        if (weg.back() == -1) {
            std::cout << -1 << '\n';
            return 0;
        }
        weg.push_back(parents[weg.back()]);
    }
    for (int i = weg.size()-1; i >= 0; i--) {
        std::cout << weg[i]+1 << ' ';
    }
}
