#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    char c = 'a' + ((n - 1) % 26);
    cout << ((n + 25) / 26) + 1 << ' ' << c << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
