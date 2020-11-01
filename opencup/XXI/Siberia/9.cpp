#include <bits/stdc++.h>

using namespace std;

long double binpow(long long a, long long n) {
	long double res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

long double probab(long long n, long long f, long long m, long long bound) {
    std::vector<std::vector<long long> > value(n, std::vector<long long>(n*f, 0));
    for (long long i = 0; i < f; ++i)
        value[0][i] = 1;
    long long i, j, k;
    for (i = 1; i < n; ++i) {
        for (j = i; j < value[i].size(); ++j) {
            for (k = min(f, j); k > 0; --k) {
                if (j - k > -1) {
                    value[i][j] += value[i - 1][j - k];
                }
            }
        }
    }
    long long goods = 0;
    for (i = bound - m - 1; i < f * n; ++i)
        goods += value[n-1][i];
    long double fake = binpow(f, n);
    return (long double)goods/fake;
}

void solve() {
    long long w, d;
    cin >> w >> d;
    long double ans = 0;
    for (long long i = 0; i < w; ++i) {
        int n, f, m;
        cin >> n >> f >> m;
        ans = max(ans, probab(n, f, m, d));
    }
    cout << setprecision(20) << ans << '\n';
}

int main() {
    long long t;
    cin >> t;
    while (t--) solve();
}
