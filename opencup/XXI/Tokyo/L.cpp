#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;
using ull = unsigned long long;
const ull MOD = 998244353;

ull binpow(ull a, ull n) {
	ull res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n;
    std::cin >> n;
    n /= 2;
    ull zn = 1;
    for (ull i = 1; i <= n; i++)
        zn = (zn * i) % MOD;
    ull ch = 1;
    for (ull i = n+2; i <= 2*n; i++)
        ch = (ch * i) % MOD;
    std::cout << (ch * binpow(zn, MOD-2)) % MOD << '\n';
}
