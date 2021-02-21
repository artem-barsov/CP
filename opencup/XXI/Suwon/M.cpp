#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool stop = false;
	long long a, b, c, d;
	long long answer = 0;
	long long tmpA, tmpB, tmpC, tmpD;
	while (!stop) {
		answer = 0;
		cin >> a >> b >> c >> d;
		if ( (a == 0) && (b == 0) && (c == 0) && (d == 0) ) {
			stop = true;
			break;
		}
		while ( !(a == b && a == c && a == d) ) {
			tmpA = abs(a - b);
			tmpB = abs(b - c);
			tmpC = abs(c - d);
			tmpD = abs(a - d);
			a = tmpA;
			b = tmpB;
			c = tmpC;
			d = tmpD;
			++answer;
		}
		cout << answer << "\n";
	}
}
