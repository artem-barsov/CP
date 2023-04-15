#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Frac {
    int num, den;
    Frac(int a) : num(a), den(1) { }
    Frac(int a, int b) 
        : num(a / gcd(a, b)), den(b / gcd(a, b)) { }
    Frac(Frac a, Frac b) 
        : Frac(a.num * b.den, a.den * b.num) { }
    friend Frac operator+(int lhs, Frac rhs) {
        return Frac(lhs * rhs.den + rhs.num, rhs.den);
    }
};

Frac calc(queue<int>& a, queue<int>& b) {
    if (a.empty()) return 0;
    int ai = a.front();
    int bi = b.front();
    a.pop();
    b.pop();
    return Frac(bi, ai + calc(a, b));
}

void solve() {
    int n;
    cin >> n;
    queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push(x);
    }
    Frac ans = calc(a, b);
    cout << ans.num << ' ' << ans.den << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}