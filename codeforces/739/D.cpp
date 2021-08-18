#include <bits/stdc++.h>

using namespace std;

int simil(std::string& sn, std::string&& bp) {
    int ret = 0, i = 0, j = 0;
    while (i < sn.length() && j < bp.length()) {
        if (sn[i] != bp[j])
            ret++;
        else
            j++;
        i++;
    }
    if (i == sn.length())
        ret += bp.length() - j;
    else
        ret += sn.length() - i;
    return ret;
}

void solve() {
    std::string n;
    std::cin >> n;
    int ans = INT_MAX;
    for (unsigned long long i = 1; i  > 0; i <<= 1ull) {
        ans = min(ans, simil(n, to_string(i)));
    }
    std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
