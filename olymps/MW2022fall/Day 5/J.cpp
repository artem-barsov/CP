#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

string least_pal(const string& s) {
    if (s == "10") return "9";
    string t = s.substr(0, s.length()/2);
    string t_rev = t;
    reverse(t_rev.begin(), t_rev.end());
    if (s.length()&1) t += s[s.length()/2];
    t += t_rev;
    if (t <= s)
        return t;
    for (int i = (s.length()-1)/2; i >= 0; i--) {
        if (t[i] > '0') {
            t[i]--;
            break;
        }
        t[i] = '9';
    }
    for (int i = (s.length()-1)/2+1; i < t.length(); i++)
        t[i] = '9';
    if (t[0] == '0') t = t.substr(1);
    return least_pal(t);
}

void substract(string& s, const string& t) {
    for (int i1 = s.length()-1, i2 = t.length()-1; i1 >= 0 && i2 >= 0; i1--, i2--) {
        if (s[i1] >= t[i2]) s[i1] = '0' + s[i1] - t[i2];
        else {
            s[i1] = '0' + 10 + (s[i1]-'0') - (t[i2]-'0');
            if (i1-1 >= 0) s[i1-1]--;
        }
    }
    if (s.length() > 1) {
        int from = 0;
        while (from < s.length() && s[from] == '0') from++;
        s = s.substr(min(from, (int)s.length()-1));
    }
}

void solve() {
    string s;
    cin >> s;
    vector<string> vout;
    while (s != "0") {
        string lp = least_pal(s);
        substract(s, lp);
        vout.push_back(lp);
    }
    cout << vout.size() << '\n';
    for (auto &&x : vout)
        cout << x << '\n';    
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}