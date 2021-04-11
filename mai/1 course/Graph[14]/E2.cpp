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
    ull n, q;
    std::cin >> n >> q;
    std::vector<std::vector<Edge> > edges(n);
    for (ull i = 0; i < n; i++) {
        for (ull j = 0; j < n; j++) {
            ull w;
            std::cin >> w;
            edges[i].push_back(Edge{j, w});
            // edges[v].push_back(Edge{u, w});
        }
    }
    std::vector<ull> qs;
    for (int i = 0; i < q; i++) {
        std::cin >> qs[i];
    }
    for (ull i = 0; i < q; i++) {
        std::vector<ull> distances(n, 10000000000);
        std::vector<ull> relaxed(n);
        int s = qs[i];
        distances[s] = 0;
        priority_queue<Priority> pq;
        pq.push(Priority{0, s});
        while (!pq.empty()) {
            Priority u = pq.top();
            pq.pop();
            if (relaxed[u.vertex]) continue;
            relaxed[u.vertex] = 1;
            for (const Edge& e : edges[u.vertex]) {
                if (distances[e.to] > distances[u.vertex] + e.w) {
                    distances[e.to] = distances[u.vertex] + e.w;
                    pq.push(Priority{distances[e.to], e.to});
                }
            }
        }
        for (ull i = 0; i < n; i++) {
            if (distances[i] < 10000000000) std::cout << distances[i] << ' ';
            else std::cout << -1 << ' ';
        }
    }
}
