#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> a, b, c;
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case 'A':
                a.insert(i);
                break;
            case 'B':
                b.insert(i);
                break;
            case 'C':
                c.insert(i);
                break;
        }
    }
    vector<pair<int, int>> ans;
    int bc = n - a.size();
    for (int i = 0; i < bc; ++i) {
        auto b_it = b.begin();
        if (b_it == b.end()) {
            cout << "NO\n";
            return 0;
        }
        auto c_it = c.upper_bound(*b_it);
        if (c_it == c.end()) {
            cout << "NO\n";
            return 0;
        }
        ans.push_back({*b_it, *c_it});
        c.erase(c_it);
        b.erase(b_it);
    }
    int a_size = a.size();
    for (int i = 0; i < a_size; ++i) {
        auto a_it = a.begin();
        auto b_it = b.lower_bound(*a_it);
        auto c_it = c.lower_bound(*a_it);
        if (b_it != b.end() && c_it != c.end()) {
            if (*b_it < *c_it) {
                ans.push_back({*a_it, *b_it});
                b.erase(b_it);
            } else {
                ans.push_back({*a_it, *c_it});
                c.erase(c_it);
            }
        } else if (b_it != b.end()) {
            ans.push_back({*a_it, *b_it});
            b.erase(b_it);
        } else if (c_it != c.end()) {
            ans.push_back({*a_it, *c_it});
            c.erase(c_it);
        } else {
            cout << "NO\n";
            return 0;
        }
        a.erase(a_it);
    }
    if (b.size() || c.size()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}
