#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int p = 998244353;
using ull = unsigned long long;

ull binpow(ull a, ull n) {
	ull res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % p;
		a = (a * a) % p;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int c[26];
	vector<ull> facs(10001, 1);
	for (ull i = 1; i < 10001; ++i) {
		facs[i] = (i * facs[i - 1]) % p;
	}
	for (int i = 0; i < 26; ++i) {
		c[i] = 0;
	}
	int n = s.size();
	if (n > p) {
		cout << 0 << std::endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		++c[s[i] - 'a'];
	}
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < 26; ++i) {
		c2 += c[i] / 2;
		c1 += c[i] % 2;
	}
	if (c1 > 1) {
		cout << 0 << "\n";
		return 0;
	}
	ull ch = facs[c2];
	ull zn = facs[n];
	for (int i = 0; i < 26; ++i) {
		ch = (ch * facs[c[i]]) % p;
	}
	for (int i = 0; i < 26; ++i) {
		zn = (zn * facs[c[i] / 2]) % p;
	}
	cout << (ch * binpow(zn, p - 2)) % p << endl;
}
