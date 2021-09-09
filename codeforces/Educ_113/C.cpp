#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

const int MAXN = 200000;
int fact[MAXN+1];
int inv_fact[MAXN+1];

int modbinpow(int a, int n, int mod) {
	int res = 1;
	while (n) {
		if (n&1) res = (res *1ull* a) % mod;
		a = (a *1ull* a) % mod;
		n >>= 1;
	}
	return res;
}

int modinv(int a, int mod) {
    return modbinpow(a, mod - 2, mod);
}

void precalc() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i-1] *1ull* i) % MOD;
    inv_fact[MAXN] = modinv(fact[MAXN], MOD);
    for (int i = MAXN-1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i+1] *1ull* (i+1)) % MOD;
}

int A(int n, int m) {
    return (fact[n] *1ull* inv_fact[n-m]) % MOD;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    sort(a.begin(), a.end());
    if (a[n-1] - a[n-2] >= 2)
        std::cout << 0 << '\n';
    else if (a[n-1] - a[n-2] == 0)
        std::cout << fact[n] << '\n';
    else {
        int pre = 1;
        while (n-pre >= 2 && a[n-pre-1] == a[n-pre-2]) pre++;
        int ans = fact[n];
        int k = fact[n-pre-1];
        for (int i = n-1; i >= pre; i--)
            ans = (MOD + ans - (k *1ull* A(i, pre)) % MOD) % MOD;
        std::cout << ans << '\n';
    }
}

int main(int argc, char const *argv[]) {
    precalc();
    int t;
    std::cin >> t;
    while (t--) solve();
}
