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
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    map<pair<char,char>, set<string>> dict;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char l = s.front(), r = s.back();
        sort(s.begin(), s.end());
        dict[{l, r}].insert(s);
    }
    int m;
    cin >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        char l = s.front(), r = s.back();
        sort(s.begin(), s.end());
        if (dict.contains({l, r}) && dict[{l, r}].contains(s))
            cnt++;
    }
    cout << m - cnt << '\n';
}