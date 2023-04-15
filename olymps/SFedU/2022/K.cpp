#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Point {
    double x, y;
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    Point p1(10, 2);
    Point p2(-8, 1);
    Point c = {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0};
    double k = (double)(p2.y - p1.y) / (p2.x - p1.x);
    k = - 1 / k;
    double b = c.y - k * c.x;
    double nx = - b / k;

    printf("c.x = %f, c.y = %f\n", c.x, c.y);
    printf("k = %f\n", k);
    printf("b = %f\n", b);
    printf("nx = %f\n", nx);
}
