#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int ans = 0;

pair<int,int> f(vector<int>& a, int l, int r) {
    if (ans == -1) return{};
    if (l == r) return {a[l], a[r]};
    auto [ll, lr] = f(a, l, (l+r)/2);
    if (ans == -1) return{};
    auto [rl, rr] = f(a, (l+r)/2+1, r);
    if (ans == -1) return{};
    if (lr > rl) {
        swap(ll, rl);
        swap(lr, rr);
        if (ans != -1) ans++;
    }
    if (rl - lr != 1) ans = -1;
    return {ll, rr};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    ans = 0;
    f(a, 0, n-1);
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