#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int dfs(std::vector<std::vector<int> >& gra, std::vector<int>& tin,
         std::vector<int>& tout, int u, int t) {
    tin[u] = t;
    for (int v : gra[u]) {
        t = dfs(gra, tin, tout, v, t + 1);
    }
    return tout[u] = t + 1;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > gra(n);
    int root;
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        if (p) gra[p-1].push_back(i);
        else root = i;
    }
    std::vector<int> tin(n);
    std::vector<int> tout(n);
    dfs(gra, tin, tout, root, 0);
    int m;
    std::cin >> m;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        std::cout << (tin[a]<=tin[b] && tout[b]<=tout[a]) << '\n';
    }
}
