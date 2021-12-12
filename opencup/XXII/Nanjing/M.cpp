#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    ll sum = 0;
    int mn = abs(a[0]);
    int b = 0, m = 0;
    for (auto &it : a) {
        mn = min(abs(it), mn);
        sum += abs(it);
        if (it < 0) m++;
        else b++;
    }
    if (m == 0 || b == 0) {
        cout << sum - 2 * mn << endl;
    } else {
        cout << sum << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    signed t;
    cin >> t;
    while(t--)
        solve();
}
