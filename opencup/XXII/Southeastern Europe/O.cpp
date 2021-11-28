#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans = 0;
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] < t[i]) {
            ans += c * (n - i);
            c = 1;
        } else if (s[i] == t[i]) {
            c++;
        } else {
            c = 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
