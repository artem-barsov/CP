#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(1);
    cin >> a[0];
    for (int i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        if (x > a[0]) a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++) {
        if (a[0] < a[i])
            a[0] += (a[i] - a[0] + 1ll) / 2;
    }
    cout << a[0] << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}