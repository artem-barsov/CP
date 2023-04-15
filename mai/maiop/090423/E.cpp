#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

const int INF = INT_MAX / 4;

int r, c, k;

struct Point {
    int i, j;
};

Point p_diffs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(const Point& p) {
    return (p.i >= 0) && (p.i < r) && (p.j >= 0) && (p.j < c);
}

Point operator+(const Point& lhs, const Point& rhs) {
    return {lhs.i + rhs.i, lhs.j + rhs.j};
}

struct State {
    Point p;
    int k, d;
};

void solve() {
    cin >> r >> c >> k;

    vector<vector<vector<int>>> dp(
        r, vector<vector<int>>(c, vector<int>(k + 1, INF)));

    vector<string> f(r);

    Point agent, bomb;
    for (int i = 0; i < r; ++i) {
        cin >> f[i];
        for (int j = 0; j < f[i].size(); ++j) {
            if (f[i][j] == 'A') agent = {i, j};
            if (f[i][j] == 'B') bomb = {i, j};
        }
    }

    queue<State> q;
    q.push({agent, 0, 0});

    while (!q.empty()) {
        auto st = q.front();
        q.pop();

        Point p = st.p;
        if (dp[p.i][p.j][st.k] <= st.d) {
            continue;
        }
        dp[p.i][p.j][st.k] = st.d;

        for (Point p_diff : p_diffs) {
            Point next_p = p + p_diff;
            if (!valid(next_p) || f[next_p.i][next_p.j] == '#') continue;

            bool is_door = f[next_p.i][next_p.j] == 'D';
            if (!is_door) {
                q.push({next_p, st.k, st.d + 1});
            } else if (st.k < k) {
                q.push({next_p, st.k + 1, st.d + 2});
                q.push({next_p, st.k, st.d + 3});
            }
        }
    }

    int ans = INF;
    for (auto v : dp[bomb.i][bomb.j]) ans = min(ans, v);

    if (ans == INF)
        cout << "HAHAHUHU\n";
    else
        cout << ans << '\n';
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
