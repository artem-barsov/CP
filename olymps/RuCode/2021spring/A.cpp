#include <bits/stdc++.h>

using namespace std;

int main() {
    long long one = 0;
	long long two = 0;
	int n, l;
	cin >> n >> l;
	int t, d;
	for (int i = 0; i < n; ++i) {
		cin >> t >> d;
		if (t == 1) {
			if (d == -1)
				one += 1;
			else if (d < l)
				one += 2;
			else
				one += 3;
		}
		else if ( t == 2) {
			if ( d == -1 )
				two += 1;
			else if ( d < l )
				two += 2;
			else
				two += 3;
		}
	}
	cout << one << ":" << two << "\n";
}
