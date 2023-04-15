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
    string s;
    cin >> s;
    map<int, char> cor;
    for (int i = 0; i < n; i++) {
        if (!cor.contains(a[i]))
            cor[a[i]] = s[i];
        else {
            if (cor[a[i]] != s[i]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
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