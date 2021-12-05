#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    for (char ch : s) {
        std::cout << char((ch-'a' + ('z'-'a'+1)/2) % ('z'-'a'+1) + 'a');
    }
    std::cout << '\n';
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
