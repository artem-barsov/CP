#include <bits/stdc++.h>

using namespace std;

int get(std::vector<int>& a, int x) {
	int cur = 0, mx = 0;
	for (int i = 0; i < a.size(); i++) {
		cur += x * a[i];
		mx = max(mx, cur);
		if (cur < 0) cur = 0;
	}
	return mx;
}

int main(int argc, char const *argv[]) {
    int n;
    std::string s, t;
	std::cin >> n >> s >> t;
    std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if(s[i] != t[i]) {
			if(s[i] == '1')
				a[i] = -1;
			else
				a[i] = 1;
		}
		sum += a[i];
	}
	if (sum == 0) std::cout << max(get(a, 1), get(a, -1)) << '\n';
	else std::cout << -1 << '\n';
}
