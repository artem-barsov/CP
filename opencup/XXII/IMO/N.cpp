#include <bits/stdc++.h>

using namespace std;

int main () {
    string s, t;
    cin >> s >> t;
    string s0 = "";
    for (int i = 0; i < s.size(); i += 2) {
        s0 += s[i];
    }
    string s1 = "";
    for (int i = 1; i < s.size(); i += 2) {
        s1 += s[i];
    }
    int i0 = 0, i1 = 0;
    for (int i = 0; i < t.size() && i1 < s1.size() && i0 < s0.size(); i++) {
        if (t[i] == s0[i0])
            i0++;
        if (t[i] == s1[i1])
            i1++;
    }
    if (i0 >= s0.size() || i1 >= s1.size()) cout << "Yes\n";
    else cout << "No\n";
}
