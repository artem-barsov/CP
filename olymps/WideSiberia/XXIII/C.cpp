#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

bitset<300> zero;

class Matrix {
    int n;
    array<bitset<300>, 300> rows, cols;

public:
    Matrix(){};
    Matrix(int n) : n(n){};

    Matrix(const string& s, int n) : n(n) {
        for (int row = 0; row < n; ++row) {
            for (int j = 0; j < n; ++j) {
                rows[row][j] = s[row * n + j] != '0' ? 1 : 0;
            }
        }
        for (int col = 0; col < n; ++col) {
            for (int j = 0; j < n; ++j) {
                cols[col][j] = s[n * j + col] != '0' ? 1 : 0;
            }
        }
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        Matrix ans(lhs.n);
        for (int row = 0; row < ans.n; ++row) {
            for (int j = 0; j < ans.n; ++j) {
                ans.rows[row][j] = (lhs.rows[row] & rhs.cols[j]) != zero;
            }
        }
        for (int col = 0; col < ans.n; ++col) {
            for (int j = 0; j < ans.n; ++j) {
                ans.cols[col][j] = ans.rows[j][col];
            }
        }
        return ans;
    }

    bool is_zero() const {
        for (auto& b : rows) {
            if (b != zero) return false;
        }
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Matrix> a(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        a[i] = Matrix(s, m);
    }

    Matrix v = a[0];
    int r = 0;
    for (; r + 1 < n && !v.is_zero(); ++r) {
        v = v * a[r + 1];
    }

    if (!v.is_zero()) {
        cout << "-1 -1\n";
        return;
    }

    int l = r;
    v = a[r];

    v = a[r];
    while (!v.is_zero()) {
        v = a[--l] * v;
    }

    cout << l + 1 << ' ' << r + 1 << '\n';
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
