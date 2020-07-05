#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Edge { int to, w; };

bool operator < (const Edge & lhs, const Edge & rhs) {
    if (lhs.w != rhs.w) return lhs.w < rhs.w;
    return lhs.to < rhs.to;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<Edge> > gr(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        gr[u-1].push_back(Edge{v-1, w});
        gr[v-1].push_back(Edge{u-1, w});
    }
    std::set<Edge> edges(gr[0].begin(), gr[0].end());
    std::vector<bool> used(n);
    used[0] = true;
    long long total = 0;
    while (!edges.empty()) {
        Edge e = *edges.begin();
        edges.erase(edges.begin());
        if (!used[e.to]) {
            used[e.to] = true;
            total += e.w;
            for (const Edge & next : gr[e.to]) {
                if (!used[next.to]) edges.insert(next);
            }
        }
    }
    std::cout << total << '\n';
}
