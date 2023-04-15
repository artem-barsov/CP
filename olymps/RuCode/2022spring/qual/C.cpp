#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int modbinpow(int a, int n, int mod) {
	int res = 1;
	while (n) {
		if (n&1) res = (res *1ull* a) % mod;
		a = (a *1ull* a) % mod;
		n >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n >> m;
    std::cout << modbinpow(n, n, m) << '\n';
}
