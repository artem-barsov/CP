#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct DSU {
    std::vector<int> parent, rank;
    std::vector<char> infected;
    DSU(int n)
    : parent(std::vector<int>(n))
    , rank(std::vector<int>(n, 0)), infected(n, false) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) ++rank[a];
            infected[a] |= infected[b];
        }
    }
};

int coord(int x, int y, int n) { return y * n + x; }

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m, k;
    std::cin >> n >> m >> k;
    DSU dsu(n * n);
    int ans = -1;
    std::vector<std::vector<char> > toff(n, std::vector<char>(n, false));
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        dsu.infected[coord(x, y, n)] = true;
        toff[x][y] = true;
        if ((x == 0) || (y == 0) || (x == n-1) || (y == n-1)) ans = 0;
    }
    std::vector<std::pair<int, int> > exits;
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        if (ans != -1) continue;
        if ((x == 0) || (y == 0) || (x == n-1) || (y == n-1))
            exits.emplace_back(x, y);
        toff[x][y] = true;
        if (x > 0 && toff[x-1][y])
            dsu.join(coord(x, y, n), coord(x-1, y, n));
        if (y > 0 && toff[x][y-1])
            dsu.join(coord(x, y, n), coord(x, y-1, n));
        if (x < n-1 && toff[x+1][y])
            dsu.join(coord(x, y, n), coord(x+1, y, n));
        if (y < n-1 && toff[x][y+1])
            dsu.join(coord(x, y, n), coord(x, y+1, n));
        for (auto [ex, ey] : exits) {
            if (dsu.infected[dsu.find(coord(ex, ey, n))]) ans = i + 1;
        }
    }
    std::cout << ans << '\n';
}
