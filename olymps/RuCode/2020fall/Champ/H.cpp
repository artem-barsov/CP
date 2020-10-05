#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	long long F = 0;
	long long V = 0;
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	bool mipt = false, hse = false;
	for(int i = n - 1; i >= 0; --i) {
		F += a[i];
		if (F - V >= m) {
			mipt = true;
			break;
		}
		V += b[i];
		if (V - F >= m) {
			hse = true;
			break;
		}
	}
	if (!mipt && !hse) {
		cout << "NO\n";
		return 0;
	}
    std::cout << (mipt ? "MIPT" : "HSE") << '\n';
}
