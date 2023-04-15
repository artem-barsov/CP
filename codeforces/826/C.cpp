#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    ll sum = 0;
    int ans = INT_MAX;
    for (int l = 1; l <= n; l++) {
        sum += a[l-1];
        int maxlen = l;
        ll cursum = 0;
        bool bad = false;
        for (int i = l, p = l-1; i < n; i++) {
            bad = true;
            cursum += a[i];
            if (cursum == sum) {
                maxlen = max(maxlen, i-p);
                p = i;
                cursum = 0;
                bad = false;
            }
            else if (cursum > sum) {
                bad = true;
                break;
            }
        }
        if (!bad) ans = min(ans, maxlen);
    }
    cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}