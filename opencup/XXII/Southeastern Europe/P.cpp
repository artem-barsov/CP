#include <bits/stdc++.h>
#define int long long

using namespace std;

long long llmax(long long a, long long b) {
    return a > b ? a : b;
}

void solve() {
    int n;
    cin >> n;
    n++;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    for (int i = 0; i < n; i++) {
        c[i] = llmax(0ll, b[i] - a[i]);
        a[i] = llmax(0ll, a[i] - b[i]);
    }
    int ans = 0ll;
    int req = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0) {
            if (req > a[i] || c[i] > a[i]) {
                cout << -1 << endl;
                return;
            } else {
                break;
            }
        }
        if (c[i] == 0ll) {
            if (a[i] >= req) {
                req = 0ll;
            } else {
                req -= a[i];
                req = (req + 1) / 2;
                ans += req;
            }
        } else {
            req = (c[i] + 1 + req) / 2;
            ans += req;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
