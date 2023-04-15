#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

class Frac {
public:
    int num, den;
    Frac(int a, int b) : num(a), den(b) { }
    Frac& reduced() {
        int gcd = std::gcd(num, den);
        num /= gcd;
        den /= gcd;
        return *this;
    }
    friend Frac operator+(int x, Frac val) {
        val.num += x * val.den;
        return val.reduced();
    }
    friend Frac operator/(int x, Frac val) {
        return Frac(x * val.den, val.num).reduced();
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> aa(n), bb(n);
    for (auto&& x : aa) cin >> x;
    for (auto&& x : bb) cin >> x;
    Frac val(bb.back(), aa.back());
    aa.pop_back();
    bb.pop_back();
    val.reduced();
    while (!aa.empty())
    {
        int a = aa.back();
        int b = bb.back();
        aa.pop_back();
        bb.pop_back();
        val = b / (a + val);
    }
    cout << val.num << '/' << val.den << '\n';
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