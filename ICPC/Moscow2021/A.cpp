#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it  : a) cin >> it;
    if (n == 1) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
