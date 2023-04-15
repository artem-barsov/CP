#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    int l = 0, r = n-1;
    int ans = 0;
    while (!a[l]) l++;
    while (a[r]) r--;
    while (l < r) {
        l++;
        r--;
        ans++;
        while (!a[l]) l++;
        while (a[r]) r--;
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