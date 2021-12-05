#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int x = 2;
    for (int i = 3; i <= n; i++) {
        if (i >= (x << 1))
            x <<= 1;
        ans += i - x;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
