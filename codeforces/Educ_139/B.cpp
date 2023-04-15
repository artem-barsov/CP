#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n <= 2) {
        cout << "NO" << '\n';
        return;
    }
    set<string> pats;
    for (int i = 2; i < n - 1; i++) {
        string pat;
        pat.push_back(s[i-2]);
        pat.push_back(s[i-1]);
        pats.insert(pat);
        string nxt;
        nxt.push_back(s[i]);
        nxt.push_back(s[i+1]);
        if (pats.contains(nxt)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}