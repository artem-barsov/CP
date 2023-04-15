#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

char min_c(map<char, bool>& used, char from = 'a'-1) {
    if (from == 'z') from = 'a' - 1;
    for (char c = from+1; c <= 'z'; c++)
        if (!used[c]) return c;
    return '$';
}

bool check_chain(map<char, char>& out, char c, char start_c) {
    if (c == start_c)
        return false;
    int l = 1;
    while (true) {
        l++;
        if (l == 26)
            return true;
        if (out[c]) c = out[c];
        else
            return true;
        if (c == start_c)
            return false;
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, char> out;
    map<char, bool> used;
    if (s[0] == 'a') {
        out['a'] = 'b';
        used['b'] = true;
    }
    for (char c : s) {
        if (!out[c]) {
            char mc = min_c(used);
            while (!check_chain(out, mc, c)) mc = min_c(used, mc);
            out[c] = mc;
            used[mc] = true;
        }
        cout << out[c];
    }
    cout << '\n';
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