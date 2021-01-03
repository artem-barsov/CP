#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

using Maze = std::vector<std::string>;
using Used = std::vector<std::vector<bool> >;
int n, m;

int bfs(Maze& maze, int r, int c, Used& used, int sh_down, int sh_right) {
    if (used[r][c] || (maze[r][c] == '#')) return 0;
    used[r][c] = true;
    int res = 0;
    int virt_r = (r+sh_down)%n;
    int virt_c = (c+sh_right)%m;
    if (virt_r > 0) res += bfs(maze, (r-1>=0?r-1:n-1), c, used, sh_down, sh_right);
    if (virt_r < n-1) res += bfs(maze, (r+1<n?r+1:0), c, used, sh_down, sh_right);
    if (virt_c > 0) res += bfs(maze, r, (c-1>=0?c-1:m-1), used, sh_down, sh_right);
    if (virt_c < m-1) res += bfs(maze, r, (c+1<m?c+1:0), used, sh_down, sh_right);
    return res+1;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::cin >> n >> m;
    Maze maze(n);
    int total = 0;
    int dot_r, dot_c;
    int i,j;
    for (i = 0; i < n; i++) {
        std::cin >> maze[i];
        for (j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                ++total;
                dot_r = i;
                dot_c = j;
            }
        }
    }
    Used used;
    std::queue<pair<int, int> > qout;
    int sh_down, sh_right;
    for (sh_down = 0; sh_down < n; sh_down++) {
        for (sh_right = 0; sh_right < m; sh_right++) {
            used.assign(n, std::vector<bool>(m, false));
            if (bfs(maze, dot_r, dot_c, used, sh_down, sh_right) == total) {
                qout.push({sh_down, sh_right});
            }
        }
    }
    std::cout << qout.size() << '\n';
    while (!qout.empty()) {
        std::cout << qout.front().first << ' ' << qout.front().second << '\n';
        qout.pop();
    }
}
