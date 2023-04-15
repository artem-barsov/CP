#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

const ll mod = 998244353;

ll modPow(ll a, ll n) {
    ll result = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        n /= 2;
    }
    return result;
}

ll modInverse(ll a) {
    return modPow(a, mod - 2);
}

vector<ll> fac_memo;

ll fac(ll x) {
    if (fac_memo[x]) return fac_memo[x];

    fac_memo[x] = x * fac(x - 1);
    return fac_memo[x];
}

ll C(ll n, ll k) {
    return fac(n) * modInverse(fac(k)) % mod * modInverse(fac(n - k)) % mod;
}

ll stir(ll n, ll k) {
    ll sum = 0;
    for (int i = 0; i <= k; ++i) {
        ll v = C(k, i) * modPow(i, n) % mod;

        if ((k - i) % 2 == 0) {
            sum = (sum + v) % mod;

        } else {
            sum = (sum - v + mod) % mod;
        }
    }
    return (sum * modInverse(fac(k))) % mod;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    fac_memo.resize(1'000'500);
    fac_memo[0] = 1;

    ll n, k;
    cin >> n >> k;

    ll st = stir(n + k, k);
    ll mi = modInverse(C(n + k - 1, k));
    ll gcd1 = gcd(st, mi);
    st /= gcd1;
    mi /= gcd1;
    cout << st * mi % mod << endl;

    return 0;
}
