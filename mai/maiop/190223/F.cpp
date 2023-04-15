#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

pair<bool, vector<int>> fits(const string& s, const string& pat) {
    if (s.size() < pat.size()) return {false, {}};
    int t = 0;
    vector<int> ret;
    for (int i = 0; i < pat.size(); i++) {
        while (t < s.size() && s[t] != pat[i]) {
            ret.push_back(t);
            t++;
        }
        if (t != s.size()) t++;
        else return {false, {}};
    }
    for (int i = t; i < s.size(); i++)
        ret.push_back(i);
    return {true, ret};
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    cin >> s;
    vector<string> pats = {
        "2", "3", "5", "7", "11", "19", "41", "61", "89", 
        "409", "449", "499", "881", "991", "6469", "6949", 
        "9001", "9049", "9649", "9949", "60649", "666649", 
        "946669", "60000049", "66000049", "66600049"
    };
    reverse(pats.begin(), pats.end());
    for (auto &&pat : pats) {
        auto [ok, ans] = fits(s, pat);
        if (ok) {
            cout << pat << '\n';
            if (ans.empty()) cout << -1 << '\n';
            else cout << ans << '\n';
            break;
        }
    }
}