#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll n, m;
    cin >> n >> m;
    vector<ll> sqrs, my_sqrt(m+1);
    for (ll i = 0; i*i <= m; i++) {
        sqrs.push_back(i*i);
        my_sqrt[i*i] = i;
    }
    vector<pair<ll,ll>> comps;
    for (ll sqr : sqrs) {
        if (2*sqr > m) break;
        auto lb = lower_bound(sqrs.begin(), sqrs.end(), m-sqr);
        if (lb != sqrs.end() && *lb == m-sqr)
            if (my_sqrt[sqr] < n && my_sqrt[m-sqr] < n)
                comps.emplace_back(my_sqrt[sqr], my_sqrt[m-sqr]);
    }
    vector<vector<ll>> grid(n, vector<ll>(n, -1));
    queue<tuple<ll,ll,ll>> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        auto [r, c, cnt] = q.front();
        q.pop();
        grid[r][c] = cnt;
        for (auto [lh, lv] : comps) {
            if (r-lv>=0 && c-lh>=0 && grid[r-lv][c-lh] == -1)
                q.emplace(r-lv, c-lh, cnt+1);
            if (r-lv>=0 && c+lh<n && grid[r-lv][c+lh] == -1)
                q.emplace(r-lv, c+lh, cnt+1);
            if (r+lv<n && c-lh>=0 && grid[r+lv][c-lh] == -1)
                q.emplace(r+lv, c-lh, cnt+1);
            if (r+lv<n && c+lh<n && grid[r+lv][c+lh] == -1)
                q.emplace(r+lv, c+lh, cnt+1);
            swap(lh, lv);
            if (r-lv>=0 && c-lh>=0 && grid[r-lv][c-lh] == -1)
                q.emplace(r-lv, c-lh, cnt+1);
            if (r-lv>=0 && c+lh<n && grid[r-lv][c+lh] == -1)
                q.emplace(r-lv, c+lh, cnt+1);
            if (r+lv<n && c-lh>=0 && grid[r+lv][c-lh] == -1)
                q.emplace(r+lv, c-lh, cnt+1);
            if (r+lv<n && c+lh<n && grid[r+lv][c+lh] == -1)
                q.emplace(r+lv, c+lh, cnt+1);
        }
    }
    for (auto &&row : grid) {
        for (auto &&x : row)
            cout << x << ' ';
        cout << '\n';
    }
}