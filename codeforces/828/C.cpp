#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    map<char, int> ct;
    int t = s.find_last_of('g');
    s = s.substr(t+1) + s.substr(0, t+1);
    t = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] != 'g')
            ct[s[i]] = max(ct[s[i]], t - i);
        else
            t = i;
    }
    cout << ct[c] << '\n';
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