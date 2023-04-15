#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string t;
    for (int i = n-1; i >= 0; i--) {
        if  (s[i] == '0') {
            t = char('a'+atoi(s.substr(i-2, 2).c_str())-1) + t;
            i -= 2;
        }
        else {
            t = char(s[i]-'1'+'a') + t;
        }
    }
    cout << t << '\n';
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