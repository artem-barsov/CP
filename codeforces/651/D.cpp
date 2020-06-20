#include <bits/stdc++.h>

using namespace std;

enum order { EVEN = 0, ODD = 1 };

bool check(std::vector<int>& a, int k, int x, order cur) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (cur == ODD) {
			ans++;
			cur = EVEN;
		}
		else if(a[i] <= x) {
			ans++;
			cur = ODD;
		}
	}
	return ans >= k;
}

int main(int argc, char const *argv[]) {
    int n, k;
	std::cin >> n >> k;
    std::vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
    int l = 1, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(a, k, m, EVEN) || check(a, k, m, ODD))
            r = m;
        else
            l = m + 1;
    }
    std::cout << l << '\n';
}
