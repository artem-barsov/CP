#include <bits/stdc++.h>

using namespace std;

int judge(std::string& s) {
    int p1 = 0, p2 = 0;
    int i = 1;
    for (; i <= 10; i++) {
        if (i&1) {
            p1 += s[i-1]-'0';
        }
        else {
            p2 += s[i-1]-'0';
        }
        if (p1 > p2 + 5-i/2) break;
        if (p2 > p1 + 5-(i+1)/2) break;
    }
    if (i == 11) i--;
    return i;
}

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<int> hz;
    for (size_t i = 0; i < 10; i++) {
        if (s[i] == '?') hz.push_back(i);
    }
    int m = 424242;
    for (size_t bf = 0; bf < (1 << hz.size()); bf++) {
        std::string t = s;
        bitset<10> bs(bf);
        for (size_t i = 0; i < hz.size(); i++) {
            t[hz[i]] = bs[i]+'0';
        }
        m = min(m, judge(t));
    }
    std::cout << m << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
