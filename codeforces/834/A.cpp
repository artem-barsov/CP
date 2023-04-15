#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
string yes;

void solve() {
    string s;
    cin >> s;
    cout << (yes.find(s) != string::npos ? "YES" : "NO") << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    for (int i = 0; i < 50; i++)
        yes += "Yes";
    int t;
    cin >> t;
    while (t--) solve();
}