#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

#define ANSWER(x) {std::cout << x << '\n'; return;}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    // aa
    for (int i = 0; i < n - 1; i++) {
        if (s.substr(i, 2) == "aa") ANSWER(2);
    }

    // aba
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'a' && s[i+2] == 'a')
            ANSWER(3);
    }

    // abca
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'a' && s[i+1] != s[i+2] && s[i+3] == 'a')
            ANSWER(4);
    }

    // abbacca
    for (int i = 0; i < n - 6; i++) {
        if (s[i] == 'a' && s[i+1] == s[i+2] && s[i+3] == 'a'
        && s[i+4] == s[i+5] && s[i+6] == 'a' && s[i+1] != s[i+4])
            ANSWER(7);
    }

    std::cout << -1 << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
