#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    if (!(n % 2)) {
        cout << "0 0\n";
        return;
    }
    ll ans = n / 2 + 1;
    cout << -ans << ' ' << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
