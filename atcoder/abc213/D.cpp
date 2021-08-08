#include <bits/stdc++.h>

using namespace std;

void dfs(std::vector<std::set<int> >& gra, int u) {
    std::cout << u+1 << ' ';
    while (!gra[u].empty()) {
        gra[*gra[u].begin()].erase(u);
        dfs(gra, *gra[u].begin());
        gra[u].erase(gra[u].begin());
        std::cout << u+1 << ' ';
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<std::set<int> > gra(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gra[u].insert(v);
        gra[v].insert(u);
    }
    dfs(gra, 0);
    std::cout << '\n';
}
