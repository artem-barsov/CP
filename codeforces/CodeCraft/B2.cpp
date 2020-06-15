#include <bits/stdc++.h>

using namespace std;

struct Tv {
    std::string str;
    int k;
};

bool operator < (Tv &lhs, Tv &rhs) {
    if (lhs.str != rhs.str) {
        return lhs.str < rhs.str;
    }
    return lhs.k < rhs.k;
}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<Tv> v;
    for (int k = 1; k <= n; k++) {
        std::string tmps = s.substr(k-1);
        if ((n+k)&1) tmps += s.substr(0, k-1);
        else {
            std::string revsuf = s.substr(0, k-1);
            reverse(revsuf.begin(), revsuf.end());
            tmps += revsuf;
        }
        v.push_back({tmps, k});
    }
    sort(v.begin(), v.end());
    std::cout << v[0].str << '\n' << v[0].k << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve();
}
