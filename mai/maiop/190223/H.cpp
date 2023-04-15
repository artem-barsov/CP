#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

const ll mod = 1e9 + 7;

using Matrix = vector<vector<ll>>;
Matrix P = {
    {0, 3, 0, 0},
    {1, 2, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
};

vector<ll> mult(const vector<ll>& v, const Matrix& m) {
    vector<ll> ret(4);
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            ret[j] = (ret[j] + m[i][j] * v[i] % mod) % mod;
        }
    }
    return ret;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix r(4, vector<ll>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                r[i][j] = (r[i][j] + lhs[i][k] * rhs[k][j] % mod) % mod;
            }
        }
    }
    return r;
}

Matrix mpow(Matrix a, ll n) {
    Matrix r = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    while (n) {
        if (n & 1) r = r * a;
        a = a * a;
        n >>= 1;
    }
    return r;
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    ll n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "1\n";
        exit(0);
    }

    vector<ll> v{1, 1, 2, 1};
    Matrix Pn = mpow(P, n - 2);

    v = mult(v, Pn);
    cout << v[1] << '\n';

    return 0;
}
