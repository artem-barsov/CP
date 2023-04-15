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
    int n, a, b;
    cin >> n >> a >> b;
    set<string> used_uni;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string uni, team;
        cin >> uni >> team;
        if (a && !used_uni.contains(uni)) {
            used_uni.insert(uni);
            ans.push_back(uni + ' ' + team);
            a--;
        }
        else if (b) {
            ans.push_back(uni + ' ' + team);
            b--;
        }
    }
    for (auto &&s : ans)
        cout << s << '\n';
}