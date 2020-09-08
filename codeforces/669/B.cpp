#include <bits/stdc++.h>

using namespace std;

struct Tel {
    int pos, val;
};

void solve() {
    int n;
    std::cin >> n;
    list<int> a;
    Tel best = Tel{0, 0};
    std::list<int>::iterator er = a.begin();
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        a.push_back(inp);
        if (best.val < inp) {
            best.val = inp;
            std::advance(er, i-best.pos);
            best.pos = i;
        }
    }
    std::cout << best.val << ' ';
    a.erase(++er);

    int cur_gcd = best.val;
    while (!a.empty()) {
        best = Tel{0, __gcd(cur_gcd, a.front())};
        er = a.begin();
        int b = a.front();
        for (std::list<int>::iterator it = a.begin(); it != a.end(); it++) {
            int some_gcd = __gcd(cur_gcd, *it);
            if (best.val < some_gcd) {
                best.val = some_gcd;
                er = it;
                b = *it;
            }
        }
        std::cout << b << ' ';
        a.erase(er);
        cur_gcd = best.val;
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
