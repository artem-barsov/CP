#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	string n;
	cin >> a >> b >> n;
	unsigned long long x = 0, power = 1;
	for (int i = n.length()-1; i >= 0; i--) {
		x += (((n[i] >= '0') && (n[i] <= '9')) ? (n[i]-'0') : (n[i]-'a'+10)) * power;
		power *= a;
	}
	string out;
	do {
		int mod = x % b;
		out = (char)((mod <= 9) ? (mod+'0') : (mod+'a'-10)) + out;
	} while (x /= b);
	cout << out;
}
