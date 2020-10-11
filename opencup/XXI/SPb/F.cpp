#include <bits/stdc++.h>

using namespace std;
using Table = std::vector<std::vector<bool> >;

int n;
int all = 0;
int vis = 0;
queue<pair<int, int> > qout;

bool dfs(Table& acc, int i, int j, Table& used) {
    if ((i < 1) || (j < 1) || (i > n) || j > n)
        return false;
    if (!acc[i][j] || used[i][j]) return false;
    used[i][j] = true;
    ++vis;
    qout.push(pair<int, int>(i, j));
    if (dfs(acc, i-2, j-1, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i-2, j+1, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i+2, j-1, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i+2, j+1, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i-1, j-2, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i-1, j+2, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i+1, j-2, used))
        qout.push(pair<int, int>(i, j));
    if (dfs(acc, i+1, j+2, used))
        qout.push(pair<int, int>(i, j));
    return true;
}

int main(int argc, char const *argv[]) {
    std::cin >> n;
    Table acc(n+1, std::vector<bool>(n+1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            bool ok = (__gcd(i, j) == 1);
            acc[i][j] = ok;
            acc[j][i] = ok;
            all += ok;
            if (i != j) all += ok;
        }
    }
    acc[1][1] = true;
    Table used(n+1, std::vector<bool>(n+1, false));
    dfs(acc, 1, 1, used);
    if (vis == all) {
        std::cout << qout.size() << '\n';
        while (!qout.empty()) {
            printf("%d / %d ", qout.front().first, qout.front().second);
            qout.pop();
        }
        std::cout << '\n';
    }
    else
        std::cout << -1 << '\n';
}
