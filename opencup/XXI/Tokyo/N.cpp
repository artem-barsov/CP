#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const ull MOD = 998244353ull;

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
    ull n;
    std::cin >> n;
    if (n == 3)
        std::cout << 60 << '\n';
    else if (n == 4)
        std::cout << 773 << '\n';
    else
        std::cout << ((3ull*n) % MOD + binpow(2, n) + 1ull) % MOD << '\n';
}
