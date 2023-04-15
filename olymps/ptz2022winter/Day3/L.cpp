#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = std::vector<std::vector<std::pair<int, int> > >;

const int UNUSED = -42424242;
int m = 0;

void dfs(Graph& gra, std::vector<int>& vals,
         std::map<int, std::set<int> >& used, int u, int from) {
    for (auto [v, ornt] : gra[u]) {
        if (v == from || used.contains(u) && used[u].contains(v)) continue;
// printf("from = %d, u = %d, v = %d | ", from+1, u+1, v+1);
        if (vals[v] == UNUSED) {
            vals[v] = vals[u] + ornt;
// printf("val[%d] = %d, val[%d] got = %d\n", u+1, vals[u], v+1, vals[v]);
            dfs(gra, vals, used, v, u);
        }
        else {
            m = gcd(m, abs(vals[v] - (vals[u] + ornt)));
            used[v].insert(u);
// printf("val[%d] = %d, val[%d] = %d, m got = %d\n", u+1, vals[u], v+1, vals[v], m);
        }
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, q;
    std::cin >> n >> q;
    Graph gra(n);
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        gra[x].push_back({y, +1});
        gra[y].push_back({x, -1});
    }
    std::vector<int> vals(n, UNUSED);
    std::map<int, std::set<int> > used;
    for (int i = 0; i < n; i++) {
        if (!gra[i].empty() && vals[i] == UNUSED) {
            vals[i] = 0;
            dfs(gra, vals, used, i, -1);
        }
    }
    std::queue<int> qout;
// printf("m = %d\n", m);
    if (m) {
        for (int i = 1; i <= n; i++) {
            if (m % i == 0) qout.push(i);
        }
        std::cout << qout.size() << '\n';
        while (!qout.empty()) {
            std::cout << qout.front() << ' ';
            qout.pop();
        }
        std::cout << '\n';
    }
    else {
        std::cout << n << '\n';
        for (int i = 1; i <= n; i++)
            std::cout << i << ' ';
        std::cout << '\n';
    }
}
