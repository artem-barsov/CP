#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

const int sex = 4'000'001;
int curr_add[sex * 2 + 50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int, int> m, can_add;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --curr_add[x - k + sex];
        if (curr_add[x + sex] < 0) {
            curr_add[x + sex] = 0;
            if (k == 0) curr_add[x + sex] = -1;
        }
        ++curr_add[x + sex];
        can_add[x] = max(can_add[x], curr_add[x + sex]);
        ++m[x];
    }
    int ans = 0;
    for (auto [v, c] : m) {
        ans = max(ans, c + can_add[v - k]);
    }
    cout << ans << '\n';
}
