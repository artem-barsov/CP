#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

double EPS = 1e-10;

struct Player { int x, v; };

double dist(std::vector<Player>& pl, double t) {
    double hi = pl[0].v * t + pl[0].x;
    double lo = pl[0].v * t + pl[0].x;
    for (int i = 1; i < pl.size(); i++) {
        hi = max(hi, pl[i].v * t + pl[i].x);
        lo = min(lo, pl[i].v * t + pl[i].x);
    }
    return hi - lo;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<Player> pl(n);
    Player hi(-1, 42), lo(1e7 + 1, 42);
    for (auto& [x, v] : pl) {
        std::cin >> x >> v;
        if (hi.x < x) hi = { x, v };
        if (lo.x > x) lo = { x, v };
    }
    if (hi.v == lo.v) {
        std::cout << 0 << ' ' << hi.x - lo.x << '\n';
        return 0;
    }
    double l = 0, r = 1e89;
    while (r - l > EPS) {
        double m1 = l + (r - l) / 2.7;
        double m2 = r - (r - l) / 2.7;
        double f1 = dist(pl, m1);
        double f2 = dist(pl, m2);
        if (abs(f2 - f1) < EPS)
            l = m1, r = m2;
        else if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    cout.precision(20);
    cout << l << ' ' << dist(pl, l) << endl;
}
