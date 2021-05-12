#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	if( (a == 1) && (b == 1)){
		cout << 10 << "\n";
		return 0;
	}
	if( a != 1){
		string answer = string(b + 1 - a, '9') + string((a - 1), '0');
		cout << answer << "\n";
	}
	else{
		string answer = "1" + string(b, '0');
		cout << answer << "\n";
	}
}
