#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    std::bitset<10> dig;
    for (char ch : s) dig[ch - '0'] = true;
    if (dig.all())
        std::cout << "full" << '\n';
    else {
        for (int i = 0; i < 10; i++) {
            if (!dig[i]) std::cout << i;
        }
        std::cout << '\n';
    }
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
