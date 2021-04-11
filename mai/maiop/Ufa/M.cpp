#include <bits/stdc++.h>

using namespace std;

#define myMod 1000000007

long long binpowMOD (long long a, long long n) {
	if (n == 0) return 1;
	long long answer;
	if (n % 2 == 1) {
		answer = binpowMOD(a, n - 1);
		answer = (answer * a) % myMod;
	}
	else {
		answer = binpowMOD(a, n/2);
		answer = (answer * answer) % myMod;
	}
    return answer;
}

long long GeomProgressionMOD(long long b1, long long q, long long n){
	long long answer = binpowMOD(q, n) - 1;
	answer = (answer + myMod) % myMod;
	answer = (answer * b1) % myMod;
	answer = (answer * binpowMOD(q - 1, myMod - 2)) % myMod;
	return answer;
}

long long task(long long a, long long b, long long c, long long d) {
	long long alpha = (binpowMOD(2, a) * binpowMOD(3, b)) % myMod;
	alpha = (alpha * GeomProgressionMOD(1, 3, d + 1 - b)) % myMod;
	long long answer = (GeomProgressionMOD(1, 2, c + 1 - a) * alpha) % myMod;
	return answer;
}

int main() {
    long long q;
	cin >> q;
	long long i1, i2, j1, j2;
	while (q--) {
		cin >> i1 >> i2 >> j1 >> j2;
		cout << task(i1, j1, i2, j2) << "\n";
	}
}
