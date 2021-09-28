#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++) {
        a += (s[i] == 'A');
        b += (s[i] == 'B');
        c += (s[i] == 'C');
    }
    std::cout << ((a <= b && b-a == c) ? "YES" : "NO") << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
