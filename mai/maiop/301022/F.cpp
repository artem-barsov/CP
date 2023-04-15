#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    getline(cin, s);
    int l, r;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            l = i;
            break;
        }
    }
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != ' ') {
            r = i;
            break;
        }
    }
    for (int i = l; i <= r; i++) {
        if (!('0' <= s[i]&&s[i] <= '9')) {
            cout << "invalid input" << '\n';
            return 0;
        }
    }
    while (l < s.length() && s[l] == '0') l++;
    if (l <= r)
        cout << s.substr(l, r-l+1) << '\n';
    else
        cout << 0 << '\n';
}