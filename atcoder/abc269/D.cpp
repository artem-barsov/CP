#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
class MyVector {
private:
    vector<T> a;
    int min_idx;
public:
    MyVector(int l, int r, T def = T()) : min_idx(l) {
        a.assign(r - l + 1, def);
    }
          T& operator[](size_t idx)       { return a[idx - min_idx]; }
    const T& operator[](size_t idx) const { return a[idx - min_idx]; }
    vector<T>* operator->() { return &a; }
};

void dfs(MyVector<MyVector<char>>& grid, 
         MyVector<MyVector<char>>& used, int ux, int uy) {
    used[ux][uy] = true;
    if (grid[ux-1][uy-1] && !used[ux-1][uy-1]) dfs(grid, used, ux-1, uy-1);
    if (grid[ux-1][uy  ] && !used[ux-1][uy  ]) dfs(grid, used, ux-1, uy  );
    if (grid[ux  ][uy-1] && !used[ux  ][uy-1]) dfs(grid, used, ux  , uy-1);
    if (grid[ux  ][uy+1] && !used[ux  ][uy+1]) dfs(grid, used, ux  , uy+1);
    if (grid[ux+1][uy  ] && !used[ux+1][uy  ]) dfs(grid, used, ux+1, uy  );
    if (grid[ux+1][uy+1] && !used[ux+1][uy+1]) dfs(grid, used, ux+1, uy+1);
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    MyVector<MyVector<char>> grid(-1003, 1003, MyVector<char>(-1003, 1003, false));
    MyVector<MyVector<char>> used(-1003, 1003, MyVector<char>(-1003, 1003, false));
    vector<pair<int, int>> blacks;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = true;
        blacks.emplace_back(x, y);
    }
    int cnt = 0;
    for (auto &&[x, y] : blacks) {
        if (!used[x][y]) {
            dfs(grid, used, x, y);
            cnt++;
        }
    }
    cout << cnt << '\n';
}