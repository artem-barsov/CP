#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (auto& x : a1) cin >> x;
    for (auto& x : a2) cin >> x;
    vector<unsigned long long> ps1(n+1), ps2(n+1);
    for (int i = 0; i < n; i++)
        ps1[i+1] = ps1[i] + a1[i];
    for (int i = 0; i < n; i++)
        ps2[i+1] = ps2[i] + a2[i];
    unsigned long long ans = LONG_MAX;
    for (int s = 0; s < n; s++) {
        ans = min(ans, max(ps1[n]-ps1[s+1], ps2[s]));
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
