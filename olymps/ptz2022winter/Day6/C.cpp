#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = std::vector<std::vector<int> >;

int ans = 0;

int dfs(Graph& gra, int u, int from) {
    int evens = 0, odds = 0;//, both = 0;
    for (int v : gra[u]) {
        if (v == from) continue;
        int d = dfs(gra, v, u);
        if      (d == 0) evens++;
        else if (d == 1) odds++;
        // else             both++;
    }
    if (odds < evens) {
// printf("%d: +%d\n", u+1, odds);
        ans += odds;
        return 1;
    }
    else if (odds > evens) {
// printf("%d: +%d\n", u+1, evens);
        ans += evens;
        return 0;
    }
    else if (odds != 0) {
// printf("%d: +%d\n", u+1, odds);
        ans += odds;
        return 2;
    }
    else {
        return 0;
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n;
    Graph gra(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    if (n == 2) {
        std::cout << 1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (gra[i].size() > 1) {
// printf("start from %d\n", i+1);
            dfs(gra, i, -1);
            break;
        }
    }
    std::cout << ans << '\n';
}
