#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    set<int> add;
    for (int i = 1; i <= n; i++)
        add.insert(i);
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            int x = *add.lower_bound(a[i-1]-a[i]);
            add.erase(x);
            ans[x-1] = i + 1;
        }
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