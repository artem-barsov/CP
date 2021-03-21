#include <bits/stdc++.h>

using namespace std;

int dfs(std::vector<std::string>& paper, int i, int j, std::vector<std::vector<bool> >& used) {
    if (i < 0 || j < 0 || i >= paper.size() || j >= paper[0].size() || used[i][j] || paper[i][j] == '.')
        return 0;
    used[i][j] = true;
    int vis = 1;
    vis += dfs(paper, i-1, j, used);
    vis += dfs(paper, i, j-1, used);
    vis += dfs(paper, i+1, j, used);
    vis += dfs(paper, i, j+1, used);
    return vis;
}

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> paper(n);
    int s = 0;
    int fi1 = -1, fj1 = -1, fi2 = -1, fj2 = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> paper[i];
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == '#') {
                ++s;
                fi2 = fi1; fj2 = fj1;
                fi1 = i;   fj1 = j;
            }
        }
    }
    if (s <= 2) {
        std::cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == '#') {
                paper[i][j] = '.';
                std::vector<std::vector<bool> > used(n, std::vector<bool>(m, false));
                int t;
                if (i != fi1 || j != fj1)
                    t = dfs(paper, fi1, fj1, used);
                else
                    t = dfs(paper, fi2, fj2, used);
                if (t+1 != s) {
                    std::cout << 1 << '\n';
                    return 0;
                }
                paper[i][j] = '#';
            }
        }
    }
    std::cout << 2 << '\n';
}
