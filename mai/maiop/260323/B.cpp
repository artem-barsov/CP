#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string a, b;
    cin >> a >> b;
    int bulls = 0, cows = 0;
    set<char> sa, sb;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) bulls++;
        else {
            sa.insert(a[i]);
            sb.insert(b[i]);
        }
    }
    for (char c : sa) {
        if (sb.contains(c)) cows++;
    }
    cout << bulls << ' ' << cows;
}