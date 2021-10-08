#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

using ull = unsigned long long;
const ull MOD = 1e9 + 7;

ull modbinpow(ull a, ull n, ull mod) {
	ull res = 1;
	while (n) {
		if (n&1) res = (res *1ull* a) % mod;
		a = (a *1ull* a) % mod;
		n >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull k;
    std::cin >> k;
    std::cout << (6ull * modbinpow(4, ((1ull<<k)-2), MOD)) % MOD << '\n';
}
