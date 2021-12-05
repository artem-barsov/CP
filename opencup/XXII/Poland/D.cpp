#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

int srcU (vector<vector<char>> &a) {
    int ans = 10000;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                for (int ii = i; ii >= 0; ii--) {
                    if (a[ii][j] == 'A') {
                        ans = min(ans, i - ii - 1);
                    }
                }
            }
        }
    }
    return ans;
}

int srcD (vector<vector<char>> &a) {
    int ans = 10000;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                for (int ii = i; ii < a.size(); ii++) {
                    if (a[ii][j] == 'A') {
                        ans = min(ans, ii - i - 1);
                    }
                }
            }
        }
    }
    return ans;
}

int srcR (vector<vector<char>> &a) {
    int ans = 10000;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                for (int jj = j; jj < a[0].size(); jj++) {
                    if (a[i][jj] == 'A') {
                        ans = min(ans, jj - j - 1);
                    }
                }
            }
        }
    }
    return ans;
}

int srcL (vector<vector<char>> &a) {
    int ans = 10000;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                for (int jj = j; jj >= 0; jj--) {
                    if (a[i][jj] == 'A') {
                        ans = min(ans, j - jj - 1);
                    }
                }
            }
        }
    }
    return ans;
}

void mvU (vector<vector<char>> &a, int d) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                a[i-d][j] = 'B';
                a[i][j] = '.';
            }
        }
    }
}

void mvD (vector<vector<char>> &a, int d) {
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                a[i+d][j] = 'B';
                a[i][j] = '.';
            }
        }
    }
}

void mvL (vector<vector<char>> &a, int d) {
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'B') {
                a[i][j-d] = 'B';
                a[i][j] = '.';
            }
        }
    }
}

void mvR (vector<vector<char>> &a, int d) {
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = a[0].size() - 1; j >= 0; j--) {
            if (a[i][j] == 'B') {
                a[i][j+d] = 'B';
                a[i][j] = '.';
            }
        }
    }
}

void pr(vector<vector<char>> &a) {
    for (auto k : a) {
        for (auto it : k) {
            cout << it;
        }
        cout << endl;
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> a(30, vector<char> (30, '.'));
    int ii = 10, jj = 10;
    for (int i = 0; i < n; i++, ii++) {
        for (int j = 0, jj = 10; j < m; j++, jj++) {
            char c;
            cin >> c;
            a[ii][jj] = c;
        }
    }
    string s;
    cin >> s;
    for (int i = 0; i < q; i++) {
        // pr(a);
        if (s[i] == 'N') {
            int x = srcU(a);
            if (x > 20) {
                cout << "TAK\n";
                return;
            }
            if (x != 0)
                mvU(a, x);
        }
        if (s[i] == 'S') {
            int x = srcD(a);
            if (x > 20) {
                cout << "TAK\n";
                return;
            }
            if (x != 0)
                mvD(a, x);
        }
        if (s[i] == 'E') {
            int x = srcR(a);
            if (x > 20) {
                cout << "TAK\n";
                return;
            }
            if (x != 0)
                mvR(a, x);
        }
        if (s[i] == 'W') {
            int x = srcL(a);
            if (x > 20) {
                cout << "TAK\n";
                return;
            }
            if (x != 0)
                mvL(a, x);
        }
    }
    cout << "NIE\n";
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    signed t;
    cin >> t;
    while(t--)
        solve();
}
