#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto&& x : a) cin >> x;
    a.push_back(-1);
    int idx = 1, prev_i = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < idx) continue;
        if (a[i+1] < idx+1) {
            ll rest = i - prev_i;
            ll common = idx - rest;
            ans += common * rest + rest*(rest+1)/2;
            prev_i = i;
            idx = a[i+1];
        }
        else idx++;
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