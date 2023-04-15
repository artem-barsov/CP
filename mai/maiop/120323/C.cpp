#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

bool match(string& pat, string& s) {
    for (int i = 0; i < pat.length(); i++) {
        if (pat[i] == '?') continue;
        if (pat[i] != s[i]) return false;
    }
    return true;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, k;
    string s;
    cin >> n >> k >> s;
    string sx = s;
    for (auto &&c : sx)
        if (c == '?') c = '0';
    if (s[0] == '?' && n > 1) sx[0] = '1';
    int lim = 1;
    for (int i = 0; i < sx.length(); i++)
        lim *= 10;
    int nx = stoi(sx);
    if (nx % k) nx += k - (nx % k);
    for (; nx < lim; nx += k) {
        sx = to_string(nx);
        if (match(s, sx)) {
            cout << sx << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}