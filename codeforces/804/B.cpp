#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void fit(vector<string>& a, const vector<string>& pat, int ii, int jj) {
    for (int i = 0; i < pat.size(); i++) {
        if (ii+i >= a.size()) break;
        for (int j = 0; j < pat[0].size(); j++) {
            if (jj+j >= a[0].size()) break;
            a[ii+i][jj+j] = pat[i][j];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> pat = {"1001",
                          "0110",
                          "0110",
                          "1001"};
    vector<string> a(n, string(m, '0'));
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < m; j += 4) {
            fit(a, pat, i, j);
        }
    }
    for (auto& s : a) {
        for (auto& c : s) 
            cout << c << ' ';
        cout << '\n';
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
