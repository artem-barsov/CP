#include <bits/stdc++.h>

using namespace std;

string binary(long long num, int k) {
	string answer;
	while (num > 0){
        answer.push_back(num&1 ? 'T' : 'F');
		num /= 2;
	}
	for (int i = answer.size(); i < k; ++i){
		answer.push_back('F');
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
    int n, k;
	cin >> n >> k;
	vector<string> nums(n);
	for (int i = 0; i < n; ++i){
		cin >> nums[i];
	}
	int bestMin = 0;
	int tmpMinStep;
	int i, j, score;
	for (long long step = 0; step < (1 << k); ++step){
		string s = binary(step, k);
		tmpMinStep = 1234567;
		for (i = 0; i < n; ++i){
			score = 0;
			for(j = 0; j < k; ++j){
				if( nums[i][j] == s[j]){
					++score;
				}
			}
			if( score < tmpMinStep){
				tmpMinStep = score;
			}
		}
		if( tmpMinStep > bestMin){
			bestMin = tmpMinStep;
		}
	}
	cout << bestMin << "\n";
}
