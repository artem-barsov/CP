#include <bits/stdc++.h>

#define big 20
#define small 21

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> nums(n);
		char c;
		int test;
		int answer = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			if ( c == 'S')
				nums[i] = small;
			else
				nums[i] = big;
		}
		int idxTest = k;
		for (int i = 0; i < m; ++i) {
			cin >> c;
			if ( c == 'A') {
				//ACEPTED
				idxTest = n;
			}
			else {
				//WA TEST
				cin >> test;
				if( (nums[test - 1] == small) && (idxTest >= test) ){
					++answer;
				}
				idxTest = max(idxTest, test);
			}
		}
		cout << answer << "\n";
	}
}
