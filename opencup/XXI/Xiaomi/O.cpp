#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        unsigned long long res = 0;
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == 'B') {
                res += 1ULL << (s.length() - 1 - j);
            }
        }
        cout << res << "\n";
    }
}
