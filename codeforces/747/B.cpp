#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

const int MOD = 1e9 + 7;

int modbinpow(int a, int n, int mod) {
	int res = 1;
	while (n) {
		if (n&1) res = (res *1ull* a) % mod;
		a = (a *1ull* a) % mod;
		n >>= 1;
	}
	return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0;
    while (k) {
        int t = 0;
        while ((1<<t) <= k) t++;
        ans = (ans + modbinpow(n, t - 1, MOD)) % MOD;
        k -= (1<<(t-1));
    }
    std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
