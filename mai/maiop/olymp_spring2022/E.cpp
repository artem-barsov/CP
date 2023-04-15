#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int> > gra(n);
    std::vector<std::pair<int, int> > edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
        edges.emplace_back(u, v);
    }
    std::vector<int> cells(n); // 0 - отдых, 1 - произв, 2 - жилая
    cells[0] = -1;
    int bf = 1;
    for (int i = 0; i < n; i++) bf *= 3;
    int max_prod = -1005000;
    std::vector<int> best_dump;
    while (bf--) {
        cells[0]++;
        for (int i = 1; i < n; i++) {
            if (cells[i-1] == 3) {
                cells[i]++;
                cells[i-1] = 0;
            }
        }
        int prod = 0, happy = 0;
        for (int u = 0; u < n; u++) {
            if (cells[u] == 0)      happy++;
            else if (cells[u] == 1) happy--;
        }
        for (auto [u, v] : edges) {
            if (min(cells[u], cells[v]) == 0
             && max(cells[u], cells[v]) == 2) happy++;
            if (min(cells[u], cells[v]) == 0
             && max(cells[u], cells[v]) == 1) happy--;
            if (min(cells[u], cells[v]) == 1
             && max(cells[u], cells[v]) == 2) prod++;
        }
        if (happy >= k && max_prod < prod) {
            max_prod = prod;
            best_dump = cells;
        }
    }
    std::cout << max_prod << '\n';
    std::vector<int> live_v, prod_v, rest_v;
    for (int i = 0; i < n; i++) {
        if (best_dump[i] == 0) rest_v.push_back(i);
        if (best_dump[i] == 1) prod_v.push_back(i);
        if (best_dump[i] == 2) live_v.push_back(i);
    }
    std::cout << live_v.size() << ' ';
    for (int x : live_v) std::cout << x + 1 << ' ';
    std::cout << '\n';
    std::cout << prod_v.size() << ' ';
    for (int x : prod_v) std::cout << x + 1 << ' ';
    std::cout << '\n';
    std::cout << rest_v.size() << ' ';
    for (int x : rest_v) std::cout << x + 1 << ' ';
    std::cout << '\n';
}
