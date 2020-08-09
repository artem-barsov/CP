#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MOD = 1e9 + 7;

ll binpow (ll a, ll n) {
    if (!n) return 1;
    if (n&1) {
        ll res = binpow(a, n-1) % MOD;
        res = (res * a) % MOD;
        return res;
    }
    else {
        ll b = binpow (a, n/2) % MOD;
        b = (b * b) % MOD;
        return b;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    ll x = 1;
    for (ll i = 1; i <= n; i++) x = (x*i) % MOD;
    ll ans = x - binpow(2, n-1);
    std::cout << ((ans >= 0) ? ans : ans+MOD) << '\n';
}
