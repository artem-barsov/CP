#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int idx = 0;
    while (idx < n && s[idx] == '?') idx++;
    if (idx == n) {
        for (int i = 0; i < n; i++)
            s[i] = "BR"[i&1];
    }
    else {
        if (idx != 0) {
            for (int i = idx-1; i >= 0; i--)
                s[i] = "BR"[s[i+1] == 'B'];
        }
        for (int i = idx; i < n; i++) {
            if (s[i] != '?') continue;
            s[i] = "BR"[s[i-1] == 'B'];
        }
    }
    std::cout << s << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
