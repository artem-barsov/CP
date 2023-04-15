#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            if (c[i][j] == -1) c[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (c[a[i]][a[i+1]] == INT_MAX) {
            cout << -1 << '\n';
            return 0;
        }
        ans += c[a[i]][a[i+1]];
    }
    if (c[a.back()][a[0]] == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }
    ans += c[a.back()][a[0]];
    cout << ans << '\n';
}