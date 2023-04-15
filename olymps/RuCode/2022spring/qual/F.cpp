#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void dfs(std::vector<std::vector<int> >& gra, std::vector<char>& used, int u) {
    used[u] = true;
    for (int v : gra[u]) {
        if (used[v]) continue;
        dfs(gra, used, v);
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > gra(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    if (m != n - 1) {
        std::cout << "NO" << '\n';
        return 0;
    }
    std::vector<char> used(n, false);
    dfs(gra, used, 0);
    for (bool us : used) {
        if (!us) {
            std::cout << "NO" << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
}
