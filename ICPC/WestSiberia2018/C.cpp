#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    std::string s;
    std::cin >> s;
    int k = s.size();
    std::array<int, 26> v;
    for (int i = 0; i < 26; ++i) {
        v[i] = -1;
    }
    int m = 0, l = 0;
    for (int i = 0; i < k; ++i) {
        int c = s[i] - 'a';
        if (v[c] != -1) {
            while (l <= v[c]) {
                v[s[l] - 'a'] = -1;
                ++l;
            }
        }
        v[c] = i;
        m = std::max(m, i - l + 1);
    }
    std::cout << m << std::endl;
}
