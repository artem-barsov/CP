#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (auto &&x : v) os << x << '\n';
    return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &&x : v) is >> x;
    return is;
}

struct Solver
{
vector<vector<int>> gra;
vector<ull> s;
vector<ull> max_val;

ull dfs_max_val(int u) {
    ull mv = 0;
    for (int v : gra[u])
        mv = max(mv, dfs_max_val(v));
    return max_val[u] = s[u] + mv;
}

ull dfs(int u, ull k) {
    ull ret = k * s[u];
    if (gra[u].empty())
        return ret;
    ull t = k / gra[u].size();
    int rem = k % gra[u].size();
    for (int i = 0; i < gra[u].size(); i++) {
        ret += dfs(gra[u][i], t+(i<rem));
    }
    return ret;
}

void solve() {
    int n, k;
    cin >> n >> k;
    gra.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gra[p].push_back(i);
    }
    s.resize(n);
    cin >> s;
    max_val.resize(n);
    dfs_max_val(0);
    for (auto &&vs : gra) {
        sort(vs.begin(), vs.end(), [&](const int& lhs, const int& rhs) {
            return max_val[lhs] > max_val[rhs];
        });
    }
    ull ans = dfs(0, k);
    cout << ans << '\n';
}
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) Solver().solve();
}