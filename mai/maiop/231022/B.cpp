#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Frac {
    int num, den;
    Frac() : num(0), den(1) { }
    Frac(int a) : num(a), den(1) { }
    Frac(int a, int b) 
        : num(a / gcd(a, b)), den(b / gcd(a, b)) { }
    Frac(Frac a, Frac b) 
        : Frac(a.num * b.den, a.den * b.num) { }
    friend Frac operator+(Frac lhs, Frac rhs) {
        int cd = lcm(lhs.den, rhs.den);
        return Frac(cd/lhs.den*lhs.num + cd/rhs.den*rhs.num, cd);
    }
    friend Frac operator*(Frac lhs, Frac rhs) {
        return Frac(lhs.num*rhs.num, lhs.den*rhs.den);
    }
    friend Frac operator/(Frac lhs, Frac rhs) {
        return Frac(lhs.num*rhs.den, lhs.den*rhs.num);
    }
    friend istream& operator>>(istream& is, Frac& f) {
        char slash;
        int num, den;
        is >> num >> slash >> den;
        f = Frac(num, den);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Frac& f) {
        return os << f.num << '/' << f.den;
    }
};

Frac tact;

void solve() {
    int n;
    cin >> n;
    vector<Frac> a(n);
    int max_den = 0;
    for (auto&& x : a) {
        cin >> x;
        max_den = max(max_den, x.den);
    }
    int common_den = lcm(tact.den, max_den);
    int total_num = common_den / tact.den * tact.num;
    for (auto &&fr : a)
        total_num -= common_den / fr.den;
    Frac rest_frac(total_num, common_den);
    vector<Frac> vout;
    for (size_t i = 1; rest_frac.num; i <<= 1) {
        if (rest_frac.num & i) {
            Frac t(i, rest_frac.den);
            for (int j = 0; j < t.num; j++)
                vout.emplace_back(1, t.den);
            rest_frac.num &= ~i;
        }
    }
    cout << vout.size() << ' ';
    for (int i = int(vout.size())-1; i >= 0; i--)
        cout << vout[i] << ' ';
    cout << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> tact >> t;
    while (t--) solve();
}