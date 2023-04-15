#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

vector<vector<char>> r, l, u, d, used;
// const int MAXN = 8;
const int MAXN = 3000;

int area(int x0, int y0) {
    queue<pair<int,int>> q;
    q.emplace(x0, y0);
    int ret = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        used[x][y] = true;
        ret++;
        if (!l[x][y] && x-1 >= 0 && !used[x-1][y]) {
            q.emplace(x-1, y);
            used[x-1][y] = true;
        }
        if (!r[x][y] && x+1 <= MAXN && !used[x+1][y]) {
            q.emplace(x+1, y);
            used[x+1][y] = true;
        }
        if (!d[x][y] && y-1 >= 0 && !used[x][y-1]) {
            q.emplace(x, y-1);
            used[x][y-1] = true;
        }
        if (!u[x][y] && y+1 <= MAXN && !used[x][y+1]) {
            q.emplace(x, y+1);
            used[x][y+1] = true;
        }
    }
    return ret;
}


int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    int prev_x, prev_y;
    cin >> n;
    cin >> prev_x >> prev_y;
    r.assign(MAXN+1, vector<char>(MAXN+1, false));
    l.assign(MAXN+1, vector<char>(MAXN+1, false));
    u.assign(MAXN+1, vector<char>(MAXN+1, false));
    d.assign(MAXN+1, vector<char>(MAXN+1, false));
    used.assign(MAXN+1, vector<char>(MAXN+1, false));
    for (int i = 0; i < n; i++) {
        int xn, yn;
        cin >> xn >> yn;
        if (yn == prev_y) {
            for (int x = min(prev_x, xn); x <= max(prev_x, xn)-1; x++) {
                u[x][yn-1] = true;
                d[x][yn] = true;
            }
        }
        else {
            for (int y = min(prev_y, yn); y <= max(prev_y, yn)-1; y++) {
                r[xn-1][y] = true;
                l[xn][y] = true;
            }
        }
        prev_x = xn; 
        prev_y = yn;
    }
    cout << "asdasd\n";
    area(0, 0);
    cout << "asdasd\n";
    int ans = 0;
    for (int x = 0; x <= MAXN; x++) {
        for (int y = 0; y <= MAXN; y++) {
            if (!used[x][y])
                ans = max(ans, area(x, y));
        }
    }
    cout << ans << '\n';
}