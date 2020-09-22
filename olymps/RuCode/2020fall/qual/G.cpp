#include <bits/stdc++.h>

using namespace std;

int sqr(int x) { return x*x; }

int main(int argc, char const *argv[]) {
    int x[3], y[3];
    std::cin >> x[0] >> y[0];
    std::cin >> x[1] >> y[1];
    std::cin >> x[2] >> y[2];
    int a1q = sqr(x[0] - x[1]) + sqr(y[0] - y[1]);
    int a2q = sqr(x[1] - x[2]) + sqr(y[1] - y[2]);
    int a3q = sqr(x[0] - x[2]) + sqr(y[0] - y[2]);
    if (a1q == a2q)
        std::cout << x[0]+x[2]-x[1] << ' ' << y[0]+y[2]-y[1] << '\n';
    else if (a2q == a3q)
        std::cout << x[1]+x[0]-x[2] << ' ' << y[1]+y[0]-y[2] << '\n';
    else
        std::cout << x[2]+x[1]-x[0] << ' ' << y[2]+y[1]-y[0] << '\n';
}
