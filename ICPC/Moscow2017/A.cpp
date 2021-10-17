#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

using Graph = vector<vector<int>>;

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 1 << endl;
        return 0;
    }
    ll ans = LLONG_MAX;
    for (ll l = 1; l < k; ++l) {
        ll r = k - l;
        ll cur_ans = 1;
        ll a = l + min(l, (n - l) / 2);
        while (a != n) {
            ++cur_ans;
            ll rest = n - a;
            if (r >= rest) {
                a = n;
                continue;
            }
            a += min(a, rest / 2);
        }
        ans = min(ans, cur_ans);
    }
    cout << ans << endl;
}
