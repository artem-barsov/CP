#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    cin.ignore(1);
    string s, r;
    while (t--) {
        getline(cin, s);
        int l = s.size();
        r.clear();
        r.reserve(3 * l);
        for (int i = 0; i < l; ++i) {
            if (s[i] == ':' || s[i] == '-') {
                if (!r.empty() && (r.back() != ' '))
                    r.push_back(' ');
                r.push_back(s[i]);
                if ((i < l-1) && (s[i+1] != ' '))
                    r.push_back(' ');
            }
            else
                r.push_back(s[i]);
        }
        cout << r;
        if (t > 0) cout << '\n';
    }
}
