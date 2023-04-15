#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

double ax, ay, bx, by;
const double EPS = 1e-8;

double sum_bcd(double cy, double dx) {
    return sqrt(bx*bx + (cy-by)*(cy-by)) 
         + sqrt(dx*dx + cy*cy)
         + sqrt((dx-ax)*(dx-ax) + ay*ay);
}

double ternary_y(double x) {
    double ly = 0, ry = by;
    while (ry - ly > EPS) {
        double y1 = ly + (ry - ly) / 3;
        double y2 = ry - (ry - ly) / 3;
        double f1 = sum_bcd(y1, x);
        double f2 = sum_bcd(y2, x);
        if (f1 < f2) ry = y2;
        else         ly = y1;
    }
    return ly;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    cin >> ax >> ay >> bx >> by;
    if (ax < bx) {
        swap(ax, bx);
        swap(ay, by);
    }
    double lx = 0, rx = ax;
    while (rx - lx > EPS) {
        double x1 = lx + (rx - lx) / 3;
        double x2 = rx - (rx - lx) / 3;
        double y1 = ternary_y(x1);
        double y2 = ternary_y(x2);
        double f1 = sum_bcd(y1, x1);
        double f2 = sum_bcd(y2, x2);
        if (f1 < f2) rx = x2;
        else         lx = x1;
    }
    double ly = ternary_y(lx);
    cout.precision(10);
    // cout << lx << ' ' << ly << '\n';
    cout << fixed << sum_bcd(ly, lx) + sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by)) << '\n';
}